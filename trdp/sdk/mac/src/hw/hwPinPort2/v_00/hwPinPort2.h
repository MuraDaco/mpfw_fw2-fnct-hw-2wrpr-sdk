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
 * hwPinPort2.h
 *
 *  Created on: Jul, 26 2024
 *      Author: Marco Dau
 */


#ifndef HW_PIN_PORT_2_H
#define HW_PIN_PORT_2_H

#include "hwPinPort.h"

class hwPinPort2_t : public hwPinPort_t {

public:

    hwPinPort2_t(gpio_base_struct_t p_confPort1, gpio_base_struct_t p_confPort2);

    void vhwInit (void)  override;
    void vhwLoop (void)  override;

    hwPinPort_t  g_pinPort2;

};


#endif 	// HW_PIN_PORT_2_H
