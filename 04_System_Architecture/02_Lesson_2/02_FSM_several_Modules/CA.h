/*
 * CA.h
 *
 *  Created on: Jun 25, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef CA_H_
#define CA_H_

#include <stdio.h>
#include <stdlib.h>
#include "State.h"
#include "DC.h"
#include "US.h"

/* Global Variables */
unsigned long CA_distance ;
unsigned long CA_speed ;
unsigned long CA_threshold ;
extern unsigned long US_distance ;
extern unsigned long DC_speed ;
extern void(*DC_state)(void);

/* Collision Avoidance State ID */
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

/* State Pointer */
void(*CA_state)(void);

/* APIs */
STATE_define(CA_waiting);
STATE_define(CA_driving);
/* Central Signals */
void US_send_distance(unsigned long distance);
void DC_send_speed(unsigned long speed);


#endif /* CA_H_ */
