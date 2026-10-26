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
 * hwComCh_vUsart.h
 *
 *  Created on: Sep, 1st 2026 (Tue)
 *      Author: Marco Dau
 */


#ifndef HW_COM_CH_V_USART_H_
#define HW_COM_CH_V_USART_H_

#include "mcuComCh_rUsart.h"
#include "hwComChCmmn.h"

#include "mcuComCh_vUsartInitParams.h"


class hwComCh_vUsart_t :     public mcuComCh_rUsart_t       // (specific platform) - sdk module 
                            ,public hwComChCmmn_t           // (all platform)                        
{

    public:
        hwComCh_vUsart_t  (mcuComCh_vUsartInitParams_t* p_pConfig, comProtocolInterface_t* p_pProto);

        void hwInit_Step1 (void) override;
        void hwInit_Step2 (void) override;

        static hwComChCmmn_t* g_usart4_this;

    private:

};



#endif  //  HW_COM_CH_V_USART_H_
