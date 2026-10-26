//  *******************************************************************************
//  
//  mpfw / fw2 - Multi Platform FirmWare FrameWork
//  Copyright (C) (2023) Marco Dau
//  
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as published
//  by the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//  
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//  
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//  
//  You can contact me by the following email address
//  marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
//  
//  *******************************************************************************

/*
 * hwUsartRs485.cpp
 *
 *  Created on: Feb, 14th 2026 (Sat)
 *      Author: Marco Dau
 */


#include "hwUsartRs485.h"
#include "pin_mux.h"
#include "fsl_iocon.h"
#include "fsl_gpio.h"
#include "clock_config.h"
#include "comBufferInterface.h"




    hwUsartRs485_t::hwUsartRs485_t(hwUsartInitParams_t* p_pConfig, comProtocolInterface_t* p_pProto)  :
         mcuUsartRs485_t        (p_pConfig->register_ptr, this)
        ,hw2UsartCmmn_t         (this, p_pProto)
        ,g_pConfig              {p_pConfig}
    {}

// #define DEMO_MARCO_USART_FLEXCOMM_ID            4                       
// #define DEMO_MARCO_USART_REG_PTR                USART4                  /* see Table 422 & 429 (UM10912 User Manual)    & USART_Type struct  (LPC54608.h) */
// #define DEMO_MARCO_USART_CLOCK_ATTACH           kFRO12M_to_FLEXCOMM4    /* see Table 118 & 157 (UM10912 User Manual)    & SYSCON_Type (LPC54608.h) - typedef enum _clock_attach_id (fsl_clock.h) */
// #define DEMO_MARCO_USART_CLK_FREQ               CLOCK_GetFlexCommClkFreq(DEMO_MARCO_USART_FLEXCOMM_ID)
// #define DEMO_MARCO_USART_IRQn                   FLEXCOMM4_IRQn          /* see Table B1-4 (**DDI0403E_e_armv7m_arm.pdf** *pg B1-525*) & typedef enum IRQn USART_Type struct  (LPC54608.h) */
// #define DEMO_MARCO_USART_NVIC_PRIO              5

    hw2UsartCmmn_t* hwUsartRs485_t::g_usart4_this = nullptr;


    void hwUsartRs485_t::hwInit_Step1 (void)        {
        // CLOCK_AttachClk(kFRO12M_to_FLEXCOMM4);
        // RESET_PeripheralReset(kFC4_RST_SHIFT_RSTn);

        BOARD_BootClockPLL180M();
//        CLOCK_AttachClk(g_pConfig->clock_attach);
        // - step 1
        //      - configuring pins: tx, rx, rs485-enable-tx, rs485-enable-rx
        InitPins_IOCON();   // (see Table Table 256 pag. 196 [UM10912_LPC546xx_User_Manual.pdf])
    }

    void hwUsartRs485_t::hwInit_Step2 (void)        {
        uint8_t l_test = 0;
        g_usart4_this = this;
        if(nullptr == hw2UsartCmmn_t::g_pChannel)   {
            hw2UsartCmmn_t::g_pChannel = this;
            l_test += 1;
        }
        if(nullptr == mcuUsartRs485_t::g_pConfig)    {
            mcuUsartRs485_t::g_pConfig = this;
            l_test += 2;
        }

        InitPins_GPIO();    // (see Table Table 283 pag. 234 [UM10912_LPC546xx_User_Manual.pdf])

        // - step 2
        //      - configuring UART module

        // - step 2.1.a
        //      - load default configuration
        //
        // config.baudRate_Bps = 115200U;
        // config.parityMode = kUSART_ParityDisabled;
        // config.stopBitCount = kUSART_OneStopBit;
        // config.loopback = false;
        // config.enableTx = false;
        // config.enableRx = false;
        //
        usart_config_t config;
        USART_GetDefaultConfig(&config);
        // - step 2.1.b
        //      - default configuration customization
        config.baudRate_Bps = 9600;
        config.enableTx     = true;
        config.enableRx     = true;


        // - step 2.2
        //      - enabling and configuring UART
        // - step 2.2.a 
        //      - attach 12 MHz clock to FLEXCOMM4 (USART)
        // . CLOCK_AttachClk
        //      . input
        //          - typedef enum _clock_attach_id / clock_attach_id_t in fsl_clock.h
        //      . register
        //          - SYSCON->MAINCLKSELA / SYSCON->FCLKSEL4 (see Table Table 118 & 157 [UM10912_LPC546xx_User_Manual.pdf])
        CLOCK_AttachClk(g_pConfig->clock_attach);

        // - step 2.2.b 
        //      - enable clock and reset/start UART
        //      - set UART registers based on configuration previously set
        // . CLOCK_EnableClock(s_flexcommClocks[idx]); 
        //      . input 
        //          - typedef enum _clock_ip_name" in fsl_clock.h
        //      . register
        //          - SYSCON->AHBCLKCTRLSET register (see Table Table 118 & 140 [UM10912_LPC546xx_User_Manual.pdf])
        // . RESET_PeripheralReset(s_flexcommResets[idx]);
        //      . input:
        //          - typedef enum _SYSCON_RSTn in fsl_reset.h
        //      . register
        //          - SYSCON->PRESETCTRL / SYSCON->PRESETCTRLSET / SYSCON->PRESETCTRLCLR (see Table Table 118 & 130 [UM10912_LPC546xx_User_Manual.pdf])
        uint32_t l_clock_freq = CLOCK_GetFlexCommClkFreq(g_pConfig->flexcomm_id);
        USART_Init(g_pConfig->register_ptr, &config, l_clock_freq  );

        uint8_t l_str[] = "**.** 24.08_11:53 - Messaggio di test **";
        l_str[2] = l_test + 0x30;
        USART_WriteBlocking(g_pConfig->register_ptr, l_str, sizeof(l_str) - 1);
        // - step 2.2.c
        //      - enabling and configuring interrupt UART to use a no-blocking tx-rx procedures
        //
        //      - set priority interrupt 
        //  . NVIC_SetPriority
        //      . inputs
        //          - typedef enum IRQn / IRQn_Type in LPC54608.h
        //          - integer in the range of 0...7 (0 max priority / 7 min priority)
        //      . register
        //          - NVIC->IP regiter (see Table 89 & 104 [UM10912_LPC546xx_User_Manual.pdf])
        NVIC_SetPriority(g_pConfig->irq_n, g_pConfig->nvic_priority);

        //      - set handler of the interrupt
        //          - hang the "USART_TransferHandleIRQ" function (fsl_uasart.c) to "FLEXCOMM0_DriverIRQHandler" function (fsl_flexcomm.c)
        //          - N.B.: "FLEXCOMM0_DriverIRQHandler" is called by "FLEXCOMM0_IRQHandler" function (startup_lpc54608.cpp)
        //          - see Table 88 in [UM10912_LPC546xx_User_Manual.pdf] & Table B1-4 in [DDI0403E_e_armv7m_arm.pdf]
        // . EnableIRQ
        //      . input
        //          - typedef enum IRQn / IRQn_Type in LPC54608.h
        //      . register
        //          - NVIC->ISER register (see Table 89 & 90 [UM10912_LPC546xx_User_Manual.pdf])


        // usart_user_data.pHwUsartIntfc = this;
        // status_t USART_TransferCreateHandle(USART_Type *base,
        //                                     usart_handle_t *handle,
        //                                     usart_transfer_callback_t callback,
        //                                     void *userData)

    
        // USART_TransferCreateHandle_v2(g_pConfig->register_ptr, &g_handle, interruptHandler_0, this);

        (void)EnableIRQ(FLEXCOMM4_IRQn);

        // instance = USART_GetInstance(g_pConfig->register_ptr);

        // uint8_t l_str1[] = "01u|Messaggio di test|";
        // uint8_t l_str2[] = "01u|Messaggio di test via blocking|";
        // uint8_t l_str3[] = "*** ERRORE ***";
        //     setRxEnablePin();
        //     while(getBufferStatusFree()){};
        // (void)DisableIRQ(FLEXCOMM4_IRQn);
        // if(tx_packetSent(l_str1, sizeof(l_str1))) {
        //     while(!getBufferStatusFree()){};
        //     // USART_WriteBlocking(g_pConfig->register_ptr, l_str2, sizeof(l_str2) - 1);
        // } 
        // else {
        //    USART_WriteBlocking(g_pConfig->register_ptr, l_str3, sizeof(l_str3) - 1);
        // }
    /*
        // status_t USART_TransferCreateHandle(USART_Type *base,
        //                                     usart_handle_t *handle,
        //                                     usart_transfer_callback_t callback,
        //                                     void *userData)

        // send the first packet 
        // Tx("rsSerial build.005 - krInitStatic -> UART init OK\r\nOOO");

    */
    }

    void hwUsartRs485_t::InitPins_IOCON (void)      {
    
        /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */
        CLOCK_EnableClock(kCLOCK_Iocon);
    
        // *********************************************************************************************************
        // usart4 RX & TX pin configuration
        const uint32_t iocon_usart_config = (/* Pin is configured as FC4_RXD_SDA_MOSI */
                                             g_pConfig->icon_func |              
                                             /* No addition pin function */
                                             IOCON_PIO_MODE_INACT |
                                             /* Input function is not inverted */
                                             IOCON_PIO_INV_DI |
                                             /* Enables digital function */
                                             IOCON_PIO_DIGITAL_EN |
                                             /* Input filter disabled */
                                             IOCON_PIO_INPFILT_OFF |
                                             /* Standard mode, output slew rate control is enabled */
                                             IOCON_PIO_SLEW_STANDARD |
                                             /* Open drain is disabled */
                                             IOCON_PIO_OPENDRAIN_DI);
        /* PORT0 PIN29 (coords: K5) is configured as FC4_RXD_SDA_MOSI */
        // IOCON_PinMuxSet(IOCON, g_pConfig->rx_port, g_pConfig->rx_pin, iocon_usart_config);
        IOCON_PinMuxSet(IOCON, g_pConfig->rx_port, g_pConfig->rx_pin, iocon_usart_config);
        // IOCON_PinMuxSet(IOCON, g_pConfig->tx_port, g_pConfig->tx_pin, iocon_usart_config);
        IOCON_PinMuxSet(IOCON, g_pConfig->tx_port, g_pConfig->tx_pin, iocon_usart_config);
    
    
        // *********************************************************************************************************

        
        if(g_pConfig->rs485_enabled) {
            const uint32_t iocon_rs485_config = (/* Pin is configured as digital PIN */
                                                IOCON_PIO_FUNC0 |
                                                /* Selects pull-up function */
                                                IOCON_PIO_MODE_PULLUP |
                                                /* Input function is not inverted */
                                                IOCON_PIO_INV_DI |
                                                /* Enables digital function */
                                                IOCON_PIO_DIGITAL_EN |
                                                /* Input filter disabled */
                                                IOCON_PIO_INPFILT_OFF |
                                                /* Standard mode, output slew rate control is enabled */
                                                IOCON_PIO_SLEW_STANDARD |
                                                /* Open drain is disabled */
                                                IOCON_PIO_OPENDRAIN_DI);
            // pin to drive led 2 & max 485-DE
            /* PORT3 PIN3 (coords: A13) is configured as PIO3_3 */
            IOCON_PinMuxSet(IOCON, g_pConfig->DE_port, g_pConfig->DE_pin, iocon_rs485_config);
            // pin to drive led 3 & max 485-RE
            /* PORT3 PIN3 (coords: C3) is configured as PIO3_3 */
            IOCON_PinMuxSet(IOCON, g_pConfig->RE_port, g_pConfig->RE_pin, iocon_rs485_config);

            // enable clock & reset peripheral according with the compile time definitions
            GPIO_PortInit(GPIO, g_pConfig->DE_port);
            GPIO_PortInit(GPIO, g_pConfig->RE_port);
        }
    
   
    }

    void hwUsartRs485_t::InitPins_GPIO    (void)      {

        if(g_pConfig->rs485_enabled) {

            /* Define the init structure for the output LED pin*/
            gpio_pin_config_t out_config = {
                kGPIO_DigitalOutput,
                0,
            };

            GPIO_PinInit (GPIO, g_pConfig->DE_port, g_pConfig->DE_pin, &out_config);
            GPIO_PinInit (GPIO, g_pConfig->RE_port, g_pConfig->RE_pin, &out_config);

            // rs485 tx enable & rs485 rx disable
            setTxEnablePin();
        }
    }

    void    hwUsartRs485_t::setTxEnablePin      (void) {
        if(g_pConfig->rs485_enabled) {
            GPIO_PinWrite(GPIO, g_pConfig->DE_port, g_pConfig->DE_pin, 1);
            GPIO_PinWrite(GPIO, g_pConfig->RE_port, g_pConfig->RE_pin, 1);
        }
    }

    void    hwUsartRs485_t::clrTxEnablePin      (void) {
        setRxEnablePin();
    }

    void    hwUsartRs485_t::setRxEnablePin      (void) {
        if(g_pConfig->rs485_enabled) {
            GPIO_PinWrite(GPIO, g_pConfig->DE_port, g_pConfig->DE_pin, 0);
            GPIO_PinWrite(GPIO, g_pConfig->RE_port, g_pConfig->RE_pin, 0);
        }
    }

    void    hwUsartRs485_t::clrRxEnablePin      (void) {
        setTxEnablePin();
    }
