#   *******************************************************************************
#   
#   mpfw / fw2 - Multi Platform FirmWare FrameWork 
#       library that contains the "main" entry point and, 
#       eventualy, application code that is platform dependent
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

include_guard()

    set(CURR_MOD_NAME       FNCT-HW-2WRPR-SDK)

    set(${CURR_MOD_NAME}_sdk_SOURCE_FILES_CPP

        ## hw
        	${${CURR_MOD_NAME}_sdk_SRC_DIR}/hw/hwPinPort/v_${${CURR_MOD_NAME}_hwPinPort_VER}/hwPinPort.cpp
        	${${CURR_MOD_NAME}_sdk_SRC_DIR}/hw/com/hwComCh_rUsart/v_${${CURR_MOD_NAME}_hwComCh_rUsart_VER}/hwComCh_rUsart.cpp
        	${${CURR_MOD_NAME}_sdk_SRC_DIR}/hw/com/hwComCh_vUsart/v_${${CURR_MOD_NAME}_hwComCh_vUsart_VER}/hwComCh_vUsart.cpp

        ## prox
        	${${CURR_MOD_NAME}_sdk_SRC_DIR}/prox/hw/hwManager/v_${${CURR_MOD_NAME}_hwManager_VER}/hwManager.cpp

        ## sys
        	${${CURR_MOD_NAME}_sdk_SRC_DIR}/sys/sysTimer/v_${${CURR_MOD_NAME}_sysTimer_VER}/sysTimer.cpp

    )
