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
 * hwManager.cpp
 *
 *  Created on: Dec, 20th 2024
 *      Author: Marco Dau
 */

#include "hwManager.h"

#include "hwManagerTbl.h"

bool hwManager_t::init    (void)    {

    vhwManager_t::init();

    // 1. init hw elements 
    hw2ProxCmmn_t** l_ptrUnitArray = hwManagerTbl_t::UnitPtrArray;
    uint8_t l_id = 0;
    while(l_ptrUnitArray[l_id])    {
        l_ptrUnitArray[l_id]->hwInit();
        l_id++;
    }

    return true;
}

bool hwManager_t::init    (int argc, char *argv[])  {

    vhwManager_t::init(argc, argv);
    init();

    return true;
}

bool hwManager_t::loop    (void)    {

    vhwManager_t::body();

    // 1. loop hw elements 
    hw2ProxCmmn_t** l_ptrUnitArray = hwManagerTbl_t::UnitPtrArray;
    uint8_t l_id = 0;
    while(l_ptrUnitArray[l_id])    {
        l_ptrUnitArray[l_id]->hwLoop();
        l_id++;
    }

    return true;
}

bool hwManager_t::end     (void)    {

    vhwManager_t::end();

    // 1. end hw elements 
    hw2ProxCmmn_t** l_ptrUnitArray = hwManagerTbl_t::UnitPtrArray;
    uint8_t l_id = 0;
    while(l_ptrUnitArray[l_id])    {
        l_ptrUnitArray[l_id]->hwEnd();
        l_id++;
    }

    return true;
}



