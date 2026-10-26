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
 * hwComChCmmn.h
 *
 *  Created on: Nov, 26th 2025 (Wed)
 *      Author: Marco Dau
 */

 
#ifndef HW_2_USART_CMMN_H
#define HW_2_USART_CMMN_H

// system lib
#include <cstdint>
#include <cstddef>

#include "hwComChIntfc.h"
using namespace fw2::fnct::base::hw;
#include "comBuffer_Lin.h"
using namespace fw2::fnct::core;

#include "hw2ProxCmmn.h"


#define HW_2_USART_CMMN_TX_BUFFER_SIZE  COM_BUFFER_MAX_SIZE
#define HW_2_USART_CMMN_RX_BUFFER_SIZE  COM_BUFFER_MAX_SIZE

class hwComChCmmn_t:     public comBuffer_Lin_t
                        ,public hw2ProxCmmn_t
{

    public:
        hwComChCmmn_t  (hwComChIntfc_t* p_pChannel, comProtocolInterface_t* p_pProto);
        
        uint8_t*    rxBuff_getPtr               (void);
        uint8_t*    rxBuff_getPtrCleaned        (void);
        uint8_t     rxBuff_getLenghtCleaned     (void);
        uint8_t     rx_packetCheck              (void);

        static void interruptHandler_00  (hwComChCmmn_t* p_this);
        static void interruptHandler_0  (void* p_this);

    protected:
        void interruptHandler           (void);
        hwComChIntfc_t* g_pChannel;
        uint8_t g_data_rx;


    private:
        uint8_t g_rxBuff[HW_2_USART_CMMN_RX_BUFFER_SIZE];
};

#endif 	// HW_2_USART_CMMN_H
