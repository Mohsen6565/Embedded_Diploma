/*
 * DC.h
 *
 *  Created on: Jun 25, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef DC_H_
#define DC_H_

#include <stdio.h>
#include <stdlib.h>
#include "State.h"

/* Global Variables */
unsigned long DC_speed ;

/* DC motor State ID */
enum{
	DC_idle,
	DC_busy
}DC_state_id;

/* DC state */
void(*DC_state)(void);

/* APIs */
void DC_init(void);
STATE_define(DC_idle);
STATE_define(DC_busy);




#endif /* DC_H_ */
