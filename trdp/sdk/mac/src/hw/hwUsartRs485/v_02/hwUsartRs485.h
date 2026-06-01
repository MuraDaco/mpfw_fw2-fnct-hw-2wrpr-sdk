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


#ifndef HW_USART_RS485_H_
#define HW_USART_RS485_H_

#include "mcuUsartRs485.h"
#include "vhw2ProxCmmn.h"
#include "hw2UsartCmmn.h"

#include "hwUsartInitParams.h"
#include "comBufferStatus.h"

class hwUsartRs485_t :   public mcuUsartRs485_t     // (specific platform) - sdk module 
                        ,public vhw2ProxCmmn_t       // (all virtual platform) - processes (init, loop, end) interface (about virtual platforms)
                        ,public hw2UsartCmmn_t       // (all platform)
{

    public:
        hwUsartRs485_t  (hwUsartInitParams_t* p_pConfig, comProtocolInterface_t* p_pProto);

        void vhwInit (void) override;
        void vhwLoop (void) override;


};


#endif /* HW_USART_RS485_H_ */
