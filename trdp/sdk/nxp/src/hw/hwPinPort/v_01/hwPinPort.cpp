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
 * hwPinPort.cpp
 *
 *  Created on: Jan, 11th 2026
 *      Author: Marco Dau
 */

#include "hwPinPort.h"

// ****************************************************
// section start **** CONSTRUCTOR *****

    hwPinPort_t::hwPinPort_t(uint8_t  p_port, uint8_t p_pin, uint8_t p_dir) :
        mcuPinPort_t    (p_port, p_pin, p_dir)
    {}

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

        void hwPinPort_t::hwInit_Step1                (void)      {
 
            pinInit_Step1();
 
        }

        void hwPinPort_t::hwInit_Step2                (void)      {
 
            pinInit_Step2();
 
        }

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
