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

    hwPinPort_t::hwPinPort_t(                 uint8_t  p_port, uint8_t p_pin, uint8_t p_dir) :
        mcuPinPort_t    (         p_port, p_pin, p_dir)
    {}

//    hwPinPort_t::hwPinPort_t(                 uint8_t  p_port, uint8_t p_pin, const gpio_config_struct_t& p_config) :
//        mcuPinPort_t    (         p_port, p_pin, p_config)
//    {}


    hwPinPort_t::hwPinPort_t(uint8_t p_mcuId, uint8_t  p_port, uint8_t p_pin, const gpio_config_struct_t& p_config) :
        mcuPinPort_t    (p_mcuId, p_port, p_pin, p_config)
    {}

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    // public:
        void hwPinPort_t::vhwInit (void) {
            uint8_t* l_ptrPortArray = init(false);
            if(l_ptrPortArray) {
                g_ptrShmPort       = &l_ptrPortArray[g_port];
                g_ptrShmPortArray  = l_ptrPortArray;
            }
        }



        void hwPinPort_t::vhwLoop (void) {
            if(g_ptrShmPort)    {
                if(g_valueModified)    {
                    *g_ptrShmPort = *g_ptrPort;
                    g_valueModified = false;
                }
                else {
                    *g_ptrPort = *g_ptrShmPort;
                }
            }
        }


    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
