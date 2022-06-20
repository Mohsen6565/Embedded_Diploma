/*
 * DC_motor.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "State.h"

/* Global Variables */
unsigned long speed ;
/* DC Motor States */
enum{
	DC_idle,
	DC_busy
}DC_state_id;

/* Prototypes */
void DC_init(void);
STATE_define(DC_idle);
STATE_define(DC_busy);

/* State Pointer */
void(* DC_state)(void);


#endif /* DC_MOTOR_H_ */
