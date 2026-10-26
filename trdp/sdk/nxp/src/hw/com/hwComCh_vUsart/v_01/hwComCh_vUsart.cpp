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
 * hwComCh_vUsart.cpp
 *
 *  Created on: Sep, 1st 2026 (Tue)
 *      Author: Marco Dau
 */


#include "hwComCh_vUsart.h"

    hwComCh_vUsart_t::hwComCh_vUsart_t(mcuComCh_vUsartInitParams_t* p_pConfig, comProtocolInterface_t* p_pProto)  :
         mcuComCh_rUsart_t      (p_pConfig)
        ,hwComChCmmn_t          (this, p_pProto)
    {}


    hwComChCmmn_t* hwComCh_vUsart_t::g_usart4_this = nullptr;

    void hwComCh_vUsart_t::hwInit_Step1 (void)        {

        mcuInit_step1();
    }

    void hwComCh_vUsart_t::hwInit_Step2 (void)        {
        g_usart4_this = this;

        mcuInit_step2();
    }

