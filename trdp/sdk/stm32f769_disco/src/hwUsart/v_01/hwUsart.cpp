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
 * hwUsart.cpp
 *
 *  Created on: Nov, 26th 2025 (Wed)
 *      Author: Marco Dau
 */


// 
// ________________________________________________________________________
// // by stm32f769_disco
// bool rsSerial::s            (int p_status)    {
//     return (0 == p_status);
// }

bool rsSerial::CheckService    (void)  {
    return false;
}

void rsSerial::RxStop      (void)   {
}


void TxEnable   (void)  {
    // enable rs485-tx
    HAL_GPIO_WritePin(RS485_TX_ENABLE_GPIO_PORT, RS485_TX_ENABLE_GPIO_PIN, GPIO_PIN_SET);
    // disable rs485-rx
    HAL_GPIO_WritePin(RS485_RX_ENABLE_GPIO_PORT, RS485_RX_ENABLE_GPIO_PIN, GPIO_PIN_SET);

    /* Reset uart tx process flag (g_statusLastByteTx) */
    g_statusLastByteTx = RESET;
}

void RxEnable   (void)  {
    WaitingTransferEnd();

    // disnable rs485-tx
    HAL_GPIO_WritePin(RS485_TX_ENABLE_GPIO_PORT, RS485_TX_ENABLE_GPIO_PIN, GPIO_PIN_RESET);
    // enable rs485-rx
    HAL_GPIO_WritePin(RS485_RX_ENABLE_GPIO_PORT, RS485_RX_ENABLE_GPIO_PIN, GPIO_PIN_RESET);

}

void rsSerial::WaitingTransferEnd   (void)  {
    // Wait for the end of the transfer
    while (g_statusLastByteTx != SET){}
}

//void HAL_UART_TxCpltCallback(void)
void rsSerial::TxCallback          (void)  {

    /// tx_state = 1;
    g_statusLastByteTx = SET;
    g_callback_protocol_functions.tx_status_set__free();
    RxEnable();

}

//void HAL_UART_RxCpltCallback(void)
void rsSerial::RxCallback          (void)  {

  /* Set transmission flag: trasfer complete*/
  UartReady = SET;
}

