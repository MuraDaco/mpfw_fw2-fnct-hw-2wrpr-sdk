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
 * hwUsart.cpp
 *
 *  Created on: Nov, 26th 2025 (Wed)
 *      Author: Marco Dau
 */


#ifndef HW_USART_H_
#define HW_USART_H_

#include "hwUsartIntfc.h"


class hwUsart_t : public hwUsartIntfc_t  {

private:

    static void InitPins_IOCON      (void);
    static void InitPins_GPIO       (void);

    typedef struct _usart_user_data {
        volatile uint8_t tx_state;
        volatile uint8_t rx_state;  // never used
    } usart_user_data_t;

    static usart_user_data_t usart_user_data;

    static usart_handle_t t_handle_demo_marco;
    static usart_rtos_handle_t handle;
    static _usart_handle t_handle;
    static rtos_usart_config usart_config;

};


#endif /* HW_USART_H_ */
