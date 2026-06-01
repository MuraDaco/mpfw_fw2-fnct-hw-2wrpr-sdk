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
 * vhw2ManagerCmmn.h
 *
 *  Created on: Dec, 20th 2024
 *      Author: Marco Dau
 */


#ifndef VHW_2_MANAGER_CMMN_H
#define VHW_2_MANAGER_CMMN_H



class vhw2ManagerCmmn_t  {
                    
public:
    static void init    (void);
    static void init    (int argc, char *argv[]);

    static bool body    (void);
    static bool body    (bool p_end);

    static bool end     (void);

};


#endif 	// VHW_2_MANAGER_CMMN_H
