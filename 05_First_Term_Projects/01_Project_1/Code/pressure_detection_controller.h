/*
 * pressure_detection_controller.h
 *
 *  Created on: Jun 27, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef PRESSURE_DETECTION_CONTROLLER_H_
#define PRESSURE_DETECTION_CONTROLLER_H_

#include "State.h"
#include "driver.h"

/* Global Variabes */
volatile int PD_pressure ;
volatile int PD_alarm_sig ;
volatile int PD_pressure_threshold ;

/* PD State ID */
enum{
	PD_reading_pressure_value,
	PD_sending_alarm_signal
}PD_state_id;

/* State Pointer */
void(*PD_state)(void);

/* APIs */
void PD_init(void);
STATE_define(PD_reading_pressure_value);
STATE_define(PD_sending_alarm_signal);


#endif /* PRESSURE_DETECTION_CONTROLLER_H_ */
