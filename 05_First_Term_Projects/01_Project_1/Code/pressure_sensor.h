/*
 * pressure_sensor.h
 *
 *  Created on: Jun 27, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "State.h"
#include "driver.h"

/* Global Variables */
volatile int PS_pressure ;

/* Pressure State ID */
enum{
	PS_reading,
	PS_sending,
	PS_idle
}PS_state_id;

/* State Pointer */
void(*PS_state)(void);

/* APIs */
void PS_init(void);
STATE_define(PS_reading);
STATE_define(PS_sending);
STATE_define(PS_idle);

#endif /* PRESSURE_SENSOR_H_ */
