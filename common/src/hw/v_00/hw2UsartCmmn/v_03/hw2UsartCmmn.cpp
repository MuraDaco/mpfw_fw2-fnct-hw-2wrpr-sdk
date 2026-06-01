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
 * hw2UsartCmmn.cpp
 *
 *  Created on: Feb, 22nd 2025 (Sun)
 *      Author: Marco Dau
 */

// module include
#include "hw2UsartCmmn.h"

#include "comBufferStatus_dbgSetup.h"

    hw2UsartCmmn_t::hw2UsartCmmn_t  (hw0UsartIntfc_t* p_pChannel, comProtocolInterface_t* p_pProto):  
         comBufferStatus_t       (p_pChannel, p_pProto)
        ,g_pChannel              {p_pChannel}
    {}


    uint8_t*    hw2UsartCmmn_t::rxBuff_getPtr       (void)       {
        return g_rxBuff;
    }

    uint8_t*    hw2UsartCmmn_t::rxBuff_getPtrCleaned        (void)  {
        return  g_rxBuff + getBufferFirstDirtyBytes();
    }
    
    uint8_t     hw2UsartCmmn_t::rxBuff_getLenghtCleaned     (void)  {
        return  getBufferLengthCleaned();
    }

    uint8_t     hw2UsartCmmn_t::rx_packetCheck   (void)      {
        return rx_packetReceived(g_rxBuff, HW_2_USART_CMMN_RX_BUFFER_SIZE) ? getBufferLength() : 0;
    }



    void        hw2UsartCmmn_t::interruptHandler_0      (void* p_this)   {

        static_cast<hw2UsartCmmn_t*>(p_this)->interruptHandler();
    }
    
    void        hw2UsartCmmn_t::interruptHandler        (void)	{

    	/*  =================================================
            "virtual" case description
            --------------------------
                check shared memory buffer status
                check the "lock" status of the virtual serial comunication channel:
                if shm buffer is locked means that a process is sending a packet and hence 
                1. a byte must be read
                2. or the byte that was written/sent has been read/received from all processes, therefore
                   the writer/tx process can send another byte (standard tx interrupt) or 
                   close the transmission releasing/unlocking the shared memory buffer (completely send byte tx interrupt)

                N.B.: only one process at time can write to
            ================================================= */
    	if(g_pChannel->chkInterruptsRaised())	{
            // INTERRUPT TRIGGER of "Receive byte"/"rx overrun error" or "Send byte"/"Last byte phisically send"

    		// write/read procedure is on
        	if(g_pChannel->tx_chkInterruptRaised())	{
                // "virtual" case
    			//      . the current process is the process that write/add data to packet buffer
    			//        and all processes have read the previous data sent
                //      . it is equivalent to the "real" case tx interrupt 
                // "real" case
                //      . the tx interrupt is raised; it means that some data has to be sent
    			// therefore ...

                tx_interrupt_buffer_management();

    		} else {
                // "virtual" case
    			//      . the current process is not the process that add data to shared memory buffer (that simulates the packet buffer)
                //      . it is equivalent to the "real" case tx interrupt 
                // "real" case
                //      . the rx interrupt is raised; it means that a packet is being received

                rx_interrupt_buffer_management();

    		}
    	} else {
            // only "virtual" case
    		// the channel is free:
            // - no byte received to be managed
            // - check if there is a new packet to send
    		tx_interrupt_buffer_management();

    	}

    }


