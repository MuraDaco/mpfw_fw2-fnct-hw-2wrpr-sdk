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
 *  Created on: Feb, 23rd 2026 (Mon)
 *      Author: Marco Dau
 */


#ifndef HW_USART_RS485_H_
#define HW_USART_RS485_H_

#include "mcuUsartRs485.h"
#include "hw2ProxCmmn.h"
#include "hw2UsartCmmn.h"

#include "hwUsartInitParams.h"

 
// (specific platform) - processes (init, loop, end) interface (about virtual platforms)


class hwUsartRs485_t :   public mcuUsartRs485_t         // (specific platform) - sdk module
                        ,public hw0UsartRs485Params_t   // (specific platform) - sdk module
                        ,public hw2ProxCmmn_t           // (all platforms)     - processes (init, loop, end) interface 
                        ,public hw2UsartCmmn_t          // (all platform)

                        
{

    public:
        hwUsartRs485_t  (hwUsartInitParams_t* p_pConfig, comProtocolInterface_t* p_pProto);

        void hwInit_Step1 (void) override;
        void hwInit_Step2 (void) override;

        void    setTxEnablePin      (void) override;
        void    clrTxEnablePin      (void) override;
        void    setRxEnablePin      (void) override;
        void    clrRxEnablePin      (void) override;

        static hw2UsartCmmn_t* g_usart4_this;

    private:
        void InitPins_IOCON   (void);
        void InitPins_GPIO    (void);

        
        usart_handle_v2_t g_handle;
        hwUsartInitParams_t* g_pConfig;
        bool g_rs485_enabled;

};



#endif  //  HW_USART_RS485_H_
