/*
 * specific-data.h
 *
 *  Created on: 28 Aug. 2022
 *      Author: henry
 */

#ifndef UWAA_CAN_SYS_CAN_SWITCHER_H_
#define UWAA_CAN_SYS_CAN_SWITCHER_H_

#include "uwaa_can_sys.h"

typedef struct {
	float latitude;
	float longitude;
	float altitude;

	float accelx;
	float accely;
	float accelz;

	float temp;
	char devStatus[4];
} CAN_RX;

enum can_message_ids {

	// System Messages
	CAN_FRAME_SYSTEM_DISARMED = 0x00,
	CAN_FRAME_SYSTEM_ARMED = 0x01,
	CAN_FRAME_SYSTEM_ERROR = 0x02,
	CAN_FRAME_SYSTEM_NOMINAL = 0x03,

	// GPS Messages
	CAN_FRAME_LATITUDE = 0x20,
	CAN_FRAME_LONGITUDE = 0x21,
	CAN_FRAME_SATCOUNT = 0x22,

	// Flight Metrics
	CAN_FRAME_ALTITUDE = 0x30,
	CAN_FRAME_ACCELX = 0x31,
	CAN_FRAME_ACCELY = 0x32,
	CAN_FRAME_ACCELZ = 0x33,

	// Device Specific Updates
	CAN_FRAME_DEVICE_STATUS = 0x40,

	CAN_FRAME_DEFAULT = 0x800,

};

void CAN_ParseRx(CAN_BUS *dev, CAN_RX *crx);

#endif /* UWAA_CAN_SYS_CAN_SWITCHER_H_ */
