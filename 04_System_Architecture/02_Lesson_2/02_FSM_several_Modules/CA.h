/*
 * CA.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef CA_H_
#define CA_H_

#include "State.h"

/* Collision Avoidance States */
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

/* Prototypes */
STATE_define(CA_waiting);
STATE_define(CA_driving);

/* Global Pointer */
void(*CA_state)(void);

#endif /* CA_H_ */
