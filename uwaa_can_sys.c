/*
 * uwaa_can_sys.c
 *
 *  Created on: Aug 26, 2022
 *      Author: henry
 */

#include "uwaa_can_sys.h"

void CAN_Init(CAN_BUS *dev, CAN_HandleTypeDef *hcan, int moduleId) {
	dev->hcan = * hcan;
	dev->moduleId = moduleId;

	// Sets Default CAN Configuration;
	dev->TxHeader.RTR = CAN_RTR_DATA;
	dev->TxHeader.DLC = MAX_FRAME_SIZE;
}

void CAN_Transmit(CAN_BUS *dev, int messageId, uint8_t * _data, int dataSize) {
	dev->TxHeader.StdId = messageId;
	dev->TxHeader.DLC = dataSize;

	memcpy(&dev->TxData, _data, dataSize);

	HAL_CAN_AddTxMessage(&dev->hcan, &dev->TxHeader, dev->TxData, &dev->TxMailbox);
}

void CAN_Receive(CAN_BUS *dev) {
	HAL_CAN_GetRxMessage(&dev->hcan, CAN_RX_FIFO0, &dev->RxHeader, dev->RxData);
}
