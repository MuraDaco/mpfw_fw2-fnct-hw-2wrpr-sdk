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
 * vhwManager.cpp
 *
 *  Created on: Dec, 20th 2024
 *      Author: Marco Dau
 */

#include "vhwManager.h"


#include <iomanip>      // std::quoted()
#include <iostream>
#include <string>

#include "vhwManagerTbl.h"

bool vhwManager_t::init (void) {
    return true;
}

bool vhwManager_t::init (int argc, char *argv[]) {
    // 1. init micro & service (debug channel / virtual hardware / shared memory)

    // 1. parameters parsing
    uint8_t l_mcuId = 0;
    bool    l_shared_memory_reset = false;

    std::cout << "argc == " << argc << '\n';
 
    for(int ndx{}; ndx != argc; ++ndx) {
        std::cout << "argv[" << ndx << "] == " << std::quoted(argv[ndx]) << '\n';
        std::string l_string (argv[ndx]);
        if( "-id" == l_string)   {
            try
            {
                l_mcuId = std::stoi(argv[++ndx]); // Throws: no conversion
                std::cout << "-id parametr == " << static_cast<int> (l_mcuId) << '\n';
            }
            catch (std::invalid_argument const& ex)
            {
                std::cout << "#2: " << ex.what() << '\n';
            }
        }
        if( "--reset_shared_memory" == l_string)   {
            l_shared_memory_reset = true;
            std::cout << "shared memory reset == yes" << '\n';
        }
    }
    std::cout << "argv[" << argc << "] == "
              << static_cast<void*>(argv[argc]) << '\n';

    init_params_t l_initParams = {l_mcuId, l_shared_memory_reset};

    // 2. initialize/create shared memory about process management
    mcuManager_t::init(&l_initParams);

    // 3. init pph elements 
    vhw2ProxCmmn_t** l_ptrUnitArray = vhwManagerTbl_t::UnitPtrArray;
    uint8_t l_id = 0;
    while(l_ptrUnitArray[l_id])    {
        l_ptrUnitArray[l_id]->vhwInit();
        l_id++;
    }

    return true;
}


bool vhwManager_t::body (void) {

    if(bodyStart()) {
        vhw2ProxCmmn_t** l_ptrUnitArray = vhwManagerTbl_t::UnitPtrArray;
        uint8_t l_id = 0;
        while(l_ptrUnitArray[l_id])    {
            l_ptrUnitArray[l_id]->vhwLoop();
            l_id++;
        }
        bodyEnd();
    }
    return true;
}

bool vhwManager_t::body (bool p_end) {

    if(bodyStart()) {
        vhw2ProxCmmn_t** l_ptrUnitArray = vhwManagerTbl_t::UnitPtrArray;
        uint8_t l_id = 0;
        while(l_ptrUnitArray[l_id])    {
            l_ptrUnitArray[l_id]->vhwLoop();
            l_id++;
        }
        next();
    }
    return !p_end;
}

bool vhwManager_t::end (void) {

    // de-init micro & service (debug channel / shared memory)
    mcuManager_t::end();    // that is, shmManager_t::end()

    // 2. init pph elements 
    vhw2ProxCmmn_t** l_ptrUnitArray = vhwManagerTbl_t::UnitPtrArray;
    uint8_t l_id = 0;
    while(l_ptrUnitArray[l_id])    {
        l_ptrUnitArray[l_id]->vhwEnd();
        l_id++;
    }

    return true;
}



