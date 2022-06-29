/*
 * alarm.h
 *
 *  Created on: Jun 27, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef ALARM_H_
#define ALARM_H_

#include "State.h"
#include "driver.h"

/* Global Variabes */
volatile int AL_alarm_sig ;

/* AL State ID */
enum{
	AL_busy,
	AL_alarm_on,
	AL_alarm_off
}AL_state_id;

/* State Pointer */
void(*AL_state)(void);

/* APIs */
void AL_init(void);
void AL_turn_on(void);
void AL_turn_off(void);
STATE_define(AL_busy);
STATE_define(AL_alarm_on);
STATE_define(AL_alarm_off);


#endif /* ALARM_H_ */
