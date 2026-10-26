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
#include "vhw2ProxCmmn.h"

// ****************************************************
// section start **** CLASS DEFINITION *****

class hwPinPort_t :      public     mcuPinPort_t        // (specific platform) - sdk module
                        ,public     hw2ProxCmmn_t      // (all platform) - processs (init, loop, end) interface
                        ,public     vhw2ProxCmmn_t      // (specific platform) - processs (init, loop, end) interface about virtual platforms
{

// ****************************************************
// section start **** CONSTRUCTOR *****
    public:

    // for all platforms
        // hwPinPort_t  (                   uint8_t  p_port,    uint8_t p_pin, const gpio_config_struct_t& p_config);
        hwPinPort_t  (                   uint8_t  p_port,    uint8_t p_pin, uint8_t p_dir);
    // for the specific platform
        hwPinPort_t  (uint8_t p_mcuId,   uint8_t  p_port,    uint8_t p_pin, const gpio_config_struct_t& p_config);

    // section end   **** CONSTRUCTOR ***** 
    // ****************************************************
    // --------------------------
// ****************************************************
// section start **** PROCESS MANAGEMENT *****

    public:
        void vhwInit                (void) override;
        void vhwLoop   	            (void) override;

    // section end   **** PROCESS MANAGEMENT *****
    // ****************************************************
    // --------------------------



};


#endif 	// HW_PIN_PORT_H
