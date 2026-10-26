#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       
#   Copyright (C) (2023) Marco Dau
#   
#   This program is free software: you can redistribute it and/or modify
#   it under the terms of the GNU Affero General Public License as published
#   by the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#   
#   This program is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   GNU Affero General Public License for more details.
#   
#   You should have received a copy of the GNU Affero General Public License
#   along with this program.  If not, see <https://www.gnu.org/licenses/>.
#   
#   You can contact me by the following email address
#   marco <d o t> ing <d o t> dau <a t> gmail <d o t> com
#   
#   *******************************************************************************

### ---------------------------
##
#   set_src_ver.cmake
#
#   Created on: May, 30th 2025  (Fri)
#   Author: Marco Dau
##
### ---------------------------

set(CURR_MOD_NAME       FNCT-HW-2WRPR-SDK)

## hw
	set(${CURR_MOD_NAME}_hwPinPort_VER  			01  )
	set(${CURR_MOD_NAME}_hwPinPort2_VER  			00  )
	set(${CURR_MOD_NAME}_hwUsartInitParams_VER  	00  )
	set(${CURR_MOD_NAME}_hwComCh_rUsart_VER       	03  )
	set(${CURR_MOD_NAME}_hwComCh_vUsart_VER       	03  )
## prox
	set(${CURR_MOD_NAME}_hwManager_VER      		01  )
	set(${CURR_MOD_NAME}_vhwManager_VER      		01  )

## sys
	set(${CURR_MOD_NAME}_sysTimer_VER       		01  )
