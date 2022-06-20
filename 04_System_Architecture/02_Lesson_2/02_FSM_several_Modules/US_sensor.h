/*
 * US_sensor.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "State.h"

/* Global Variables */
unsigned long distance ;

/* US State */
enum{
	US_busy
}US_state_id;

/* Prototypes */
void US_init(void);
static unsigned long generate_random(long l, long r, long count);
STATE_define(US_busy);
/* Global pointer to function */
void(*US_state)(void);

#endif /* US_SENSOR_H_ */
