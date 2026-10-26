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
 * hw2ProxCmmn.h
 *
 *  Created on: Mar,  6th 2026 (Fri)
 *      Author: Marco Dau
 */


#ifndef     HW_PROX_CMMN_H
#define     HW_PROX_CMMN_H

#include <cstdint>

// ****************************************************
// section start **** CLASS DEFINITION *****

class hw2ProxCmmn_t
{

// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    public:
        virtual void hwInit (void) {};
        virtual void hwInit_Step1 (void) {};
        virtual void hwInit_Step2 (void) {};
        virtual void hwInit ([[maybe_unused]]void* p_initData) {};

        virtual void hwLoop (void) {};

        virtual void hwEnd (void) {};

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------


};



#endif  //  HW_PROX_CMMN_H
