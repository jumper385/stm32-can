/*
 * uwaa_can_sys.h
 *
 *  Created on: Aug 26, 2022
 *      Author: henry
 */

#ifndef UWAA_CAN_SYS_UWAA_CAN_SYS_H_
#define UWAA_CAN_SYS_UWAA_CAN_SYS_H_

#include "main.h"

#define MAX_FRAME_SIZE 8

typedef struct{
	CAN_HandleTypeDef hcan;
	int moduleId;

	uint8_t TxData[MAX_FRAME_SIZE];
	CAN_TxHeaderTypeDef TxHeader;
	uint32_t TxMailbox;

	CAN_RxHeaderTypeDef RxHeader;
	uint8_t RxData[MAX_FRAME_SIZE];
	uint32_t RxMailbox;
} CAN_BUS;

void CAN_Init(CAN_BUS *dev, CAN_HandleTypeDef *hcan, int moduleId);
void CAN_Transmit(CAN_BUS *dev, int messageId, uint8_t * _data, int dataSize);
void CAN_Receive(CAN_BUS *dev);

#endif /* UWAA_CAN_SYS_UWAA_CAN_SYS_H_ */
