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
 * hwPinPort.h
 *
 *  Created on: Jan, 11th 2026
 *      Author: Marco Dau
 */


#ifndef HW_PIN_PORT_H
#define HW_PIN_PORT_H

#include "mcuPinPort.h"
#include "hw2ProxCmmn.h"

// ****************************************************
// section start **** CLASS DEFINITION *****

class hwPinPort_t :      public     mcuPinPort_t        // (specific platform) - sdk module
                        ,public     hw2ProxCmmn_t       // (all platforms)     - processes (init, loop, end) interface 
                        
{

// ****************************************************
// section start **** CONSTRUCTOR *****
    public:

    hwPinPort_t  (uint8_t  p_port,    uint8_t p_pin, uint8_t p_dir);
    //hwPinPort_t  (uint8_t  p_port,    uint8_t p_pin, const gpio_config_struct_t& p_config);

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    public:
        void hwInit_Step1                (void) override;
        void hwInit_Step2                (void) override;

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PIN PORT MANAGEMENT *****

    public:


    // section end   **** PIN PORT MANAGEMENT *****
    // ****************************************************
    // --------------------------
// // ****************************************************
// // section start **** DISPLAY  *****
// 
//     public:
//         enum kStatusColor_t  {
//              low =  kColor_t::red
//             ,high = kColor_t::green
//         };
// 
//         static fmt_str_t g_fmtStr;
//         fmt_str_t* getPinStatusFormattedString(void) override;
//         bool update (void) override;
//         static const char* const messagesMatrix[][2];
// 
//     // section end   **** DISPLAY *****
//     // ****************************************************
//     // --------------------------



};


#endif 	// HW_PIN_PORT_H
