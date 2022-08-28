/*
 * can-switcher.c
 *
 *  Created on: 28 Aug. 2022
 *      Author: henry
 */

#include "can-switcher.h"

void CAN_ParseRx(CAN_BUS *dev, CAN_RX *crx) {
	switch (dev->RxHeader.StdId) {
			case CAN_FRAME_LATITUDE:
				memcpy(&crx->latitude, &dev->RxData, 4);
				break;
			case CAN_FRAME_LONGITUDE:
				memcpy(&crx->longitude, &dev->RxData, 4);
				break;
			case CAN_FRAME_ALTITUDE:
				memcpy(&crx->altitude, &dev->RxData, 4);
				break;
			case CAN_FRAME_DEVICE_STATUS:
				memcpy(&crx->devStatus, &dev->RxData, 4);
				break;
			default:
				break;
	}
}
