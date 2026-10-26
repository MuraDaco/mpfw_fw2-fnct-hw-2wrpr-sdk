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


#ifndef     HW_USART_INIT_PARAMS_H_
#define     HW_USART_INIT_PARAMS_H_

#include "LPC54608.h"
#include "pin_mux.h"
using namespace fw2::fnct::base::hw;

struct  hwUsartInitParams_t {

    uint32_t            flexcomm_id;
    USART_Type*         register_ptr;
    clock_attach_id_t   clock_attach;
    IRQn_Type           irq_n;
    uint32_t            nvic_priority;
    // ----------
    uint8_t             icon_func;
    uint8_t             rx_pin;
    uint8_t             rx_port;
    uint8_t             tx_pin;
    uint8_t             tx_port;
    bool                rs485_enabled;
    uint8_t             RE_pin;
    uint8_t             RE_port;
    uint8_t             DE_pin;
    uint8_t             DE_port;

};



#endif  //  HW_USART_INIT_PARAMS_H_