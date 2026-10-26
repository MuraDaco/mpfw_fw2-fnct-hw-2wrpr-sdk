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

    hwUsartRs485_t::hwUsartRs485_t(hwUsartInitParams_t* p_pConfig, comBufferInterface_t* p_pBuffer)  :
         mcuUsartRs485_t         (p_pConfig->pid2,   p_pConfig->ch)
        ,hw2UsartCmmn_t          (this, p_pBuffer)
    {}


    void hwUsartRs485_t::vhwInit (void) {
        // shmMcuUsart_t::init();
        // chEnable();
        mcuUsartRs485_t::init();
    }

    void hwUsartRs485_t::vhwLoop (void)     {
        interruptHandler();
    }
