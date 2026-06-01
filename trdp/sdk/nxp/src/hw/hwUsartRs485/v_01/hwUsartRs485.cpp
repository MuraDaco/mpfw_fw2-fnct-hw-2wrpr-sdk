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

#include "comBufferInterface.h"


    hwUsartRs485_t::hwUsartRs485_t(hwUsartInitParams_t* p_pConfig, comProtocolInterface_t* p_pProto)  :
         mcuUsartRs485_t        (DEMO_MARCO_USART_REG_PTR, p_pConfig->pConfigRs485)
        ,hw2UsartCmmn_t         (this, p_pProto)
    {}

    void hwUsartRs485_t::hwInit (void)        {
    /*        
        // - step 1
        //      - configuring pins: tx, rx, rs485-enable-tx, rs485-enable-rx
        InitPins_IOCON();
        InitPins_GPIO();

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
        CLOCK_AttachClk(DEMO_MARCO_USART_CLOCK_ATTACH);

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
        USART_Init(DEMO_MARCO_USART_REG_PTR, &config, DEMO_MARCO_USART_CLK_FREQ  );

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
        NVIC_SetPriority(DEMO_MARCO_USART_IRQn, DEMO_MARCO_USART_NVIC_PRIO);

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

    */
        USART_TransferCreateHandle_v2(DEMO_MARCO_USART_REG_PTR, &g_handle, interruptHandler_0, this);
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
        //
    //    /* Enables the clock for the IOCON block. 0 = Disable; 1 = Enable.: 0x01u */
    //    CLOCK_EnableClock(kCLOCK_Iocon);
    //
    //    // *********************************************************************************************************
    //    // usart4 RX & TX pin configuration
    //    const uint32_t port3_pin26_config = (/* Pin is configured as FC4_RXD_SDA_MOSI */
    //                                         IOCON_PIO_FUNC3 |
    //                                         /* No addition pin function */
    //                                         IOCON_PIO_MODE_INACT |
    //                                         /* Input function is not inverted */
    //                                         IOCON_PIO_INV_DI |
    //                                         /* Enables digital function */
    //                                         IOCON_PIO_DIGITAL_EN |
    //                                         /* Input filter disabled */
    //                                         IOCON_PIO_INPFILT_OFF |
    //                                         /* Standard mode, output slew rate control is enabled */
    //                                         IOCON_PIO_SLEW_STANDARD |
    //                                         /* Open drain is disabled */
    //                                         IOCON_PIO_OPENDRAIN_DI);
    //    /* PORT0 PIN29 (coords: K5) is configured as FC4_RXD_SDA_MOSI */
    //    IOCON_PinMuxSet(IOCON, 3U, 26U, port3_pin26_config);
    //
    //    const uint32_t port3_pin27_config = (/* Pin is configured as FC4_TXD_SDA_MOSI */
    //                                         IOCON_PIO_FUNC3 |
    //                                         /* No addition pin function */
    //                                         IOCON_PIO_MODE_INACT |
    //                                         /* Input function is not inverted */
    //                                         IOCON_PIO_INV_DI |
    //                                         /* Enables digital function */
    //                                         IOCON_PIO_DIGITAL_EN |
    //                                         /* Input filter disabled */
    //                                         IOCON_PIO_INPFILT_OFF |
    //                                         /* Standard mode, output slew rate control is enabled */
    //                                         IOCON_PIO_SLEW_STANDARD |
    //                                         /* Open drain is disabled */
    //                                         IOCON_PIO_OPENDRAIN_DI);
    //    /* PORT0 PIN30 (coords: P14) is configured as FC4_TXD_SDA_MOSI */
    //    IOCON_PinMuxSet(IOCON, 3U, 27U, port3_pin27_config);
    //
    //
    //    // *********************************************************************************************************
    //    // pin to read the sw2 button state
    //    const uint32_t port0_pin6_config = (/* Pin is configured as PIO0_6 */
    //                                        IOCON_PIO_FUNC0 |
    //                                        /* Selects pull-up function */
    //                                        IOCON_PIO_MODE_PULLUP |
    //                                        /* Input function is not inverted */
    //                                        IOCON_PIO_INV_DI |
    //                                        /* Enables digital function */
    //                                        IOCON_PIO_DIGITAL_EN |
    //                                        /* Input filter disabled */
    //                                        IOCON_PIO_INPFILT_OFF |
    //                                        /* Standard mode, output slew rate control is enabled */
    //                                        IOCON_PIO_SLEW_STANDARD |
    //                                        /* Open drain is disabled */
    //                                        IOCON_PIO_OPENDRAIN_DI);
    //    /* PORT0 PIN6 (coords: A5) is configured as PIO0_6 */
    //    IOCON_PinMuxSet(IOCON, 0U, 6U, port0_pin6_config);
    //
    //
    //    // pin to drive led 2 & max 485-DE
    //    const uint32_t port3_pin3_config = (/* Pin is configured as PIO3_3 */
    //                                        IOCON_PIO_FUNC0 |
    //                                        /* Selects pull-up function */
    //                                        IOCON_PIO_MODE_PULLUP |
    //                                        /* Input function is not inverted */
    //                                        IOCON_PIO_INV_DI |
    //                                        /* Enables digital function */
    //                                        IOCON_PIO_DIGITAL_EN |
    //                                        /* Input filter disabled */
    //                                        IOCON_PIO_INPFILT_OFF |
    //                                        /* Standard mode, output slew rate control is enabled */
    //                                        IOCON_PIO_SLEW_STANDARD |
    //                                        /* Open drain is disabled */
    //                                        IOCON_PIO_OPENDRAIN_DI);
    //    /* PORT3 PIN3 (coords: A13) is configured as PIO3_3 */
    //    IOCON_PinMuxSet(IOCON, 3U, 3U, port3_pin3_config);
    //
    //
    //    // *********************************************************************************************************
    //    // pin to read the sw3 button state
    //    const uint32_t port0_pin5_config = (/* Pin is configured as PIO0_6 */
    //                                        IOCON_PIO_FUNC0 |
    //                                        /* Selects pull-up function */
    //                                        IOCON_PIO_MODE_PULLUP |
    //                                        /* Input function is not inverted */
    //                                        IOCON_PIO_INV_DI |
    //                                        /* Enables digital function */
    //                                        IOCON_PIO_DIGITAL_EN |
    //                                        /* Input filter disabled */
    //                                        IOCON_PIO_INPFILT_OFF |
    //                                        /* Standard mode, output slew rate control is enabled */
    //                                        IOCON_PIO_SLEW_STANDARD |
    //                                        /* Open drain is disabled */
    //                                        IOCON_PIO_OPENDRAIN_DI);
    //    /* PORT0 PIN6 (coords: E7) is configured as PIO0_5 */
    //    IOCON_PinMuxSet(IOCON, 0U, 5U, port0_pin5_config);
    //
    //
    //    // pin to drive led 3 & max 485-RE
    //    const uint32_t port2_pin2_config = (/* Pin is configured as PIO2_2 */
    //                                        IOCON_PIO_FUNC0 |
    //                                        /* Selects pull-up function */
    //                                        IOCON_PIO_MODE_PULLUP |
    //                                        /* Input function is not inverted */
    //                                        IOCON_PIO_INV_DI |
    //                                        /* Enables digital function */
    //                                        IOCON_PIO_DIGITAL_EN |
    //                                        /* Input filter disabled */
    //                                        IOCON_PIO_INPFILT_OFF |
    //                                        /* Standard mode, output slew rate control is enabled */
    //                                        IOCON_PIO_SLEW_STANDARD |
    //                                        /* Open drain is disabled */
    //                                        IOCON_PIO_OPENDRAIN_DI);
    //    /* PORT3 PIN3 (coords: C3) is configured as PIO3_3 */
    //    IOCON_PinMuxSet(IOCON, 2U, 2U, port2_pin2_config);
    //
    }

    void hwUsartRs485_t::InitPins_GPIO    (void)      {
        //
    //    // enable clock & reset peripheral according with the compile time definitions
    //    GPIO_PortInit(GPIO, APP_BOARD_MARCO_TEST_SW2_PORT );
    //    GPIO_PortInit(GPIO, APP_BOARD_MARCO_TEST_LED2_PORT);
    //
    //    GPIO_PortInit(GPIO, APP_BOARD_MARCO_TEST_SW3_PORT );
    //    GPIO_PortInit(GPIO, APP_BOARD_MARCO_TEST_LED3_PORT);
    //
    //    /* Define the init structure for the output LED pin*/
    //    gpio_pin_config_t led_config = {
    //        kGPIO_DigitalOutput,
    //        0,
    //    };
    //
    //    GPIO_PinInit (GPIO, APP_BOARD_MARCO_TEST_LED2_PORT, APP_BOARD_MARCO_TEST_LED2_PIN, &led_config);
    //    // rs485 tx enable
    //    GPIO_PinWrite(GPIO, APP_BOARD_MARCO_TEST_LED2_PORT, APP_BOARD_MARCO_TEST_LED2_PIN, 1);
    //
    //    GPIO_PinInit (GPIO, APP_BOARD_MARCO_TEST_LED3_PORT, APP_BOARD_MARCO_TEST_LED3_PIN, &led_config);
    //    // rs485 rx disable
    //    GPIO_PinWrite(GPIO, APP_BOARD_MARCO_TEST_LED3_PORT, APP_BOARD_MARCO_TEST_LED3_PIN, 1);
    }
