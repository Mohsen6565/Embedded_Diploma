/*
 * US.h
 *
 *  Created on: Jun 25, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef US_H_
#define US_H_

#include <stdio.h>
#include <stdlib.h>
#include "State.h"

/* Global Variables */
unsigned long US_distance ;

/* Ultrasonic States ID */
enum{
	US_busy
}US_state_id;

/* State Pointer */
void(*US_state)(void);

/* APIs */
void US_init(void);
STATE_define(US_busy);
unsigned long US_get_distance(void);

#endif /* US_H_ */
