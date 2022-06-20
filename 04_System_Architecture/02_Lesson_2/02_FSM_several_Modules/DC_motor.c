/*
 * DC_motor.c
 *
 *  Created on: Jun 20, 2022
 *      Author: Mohamed Mohsen
 */
#include <stdio.h>
#include <stdlib.h>
#include "State.h"
#include "DC_motor.h"

void DC_init(void){
	/* DC initialization */
	printf("DC Initialized !\n");
}

void DC_motor_set_speed(unsigned long spd){
	speed = spd ;
	DC_state = STATE(DC_busy);
	DC_state();
}

STATE_define(DC_idle){
	/* State Action */
	DC_state_id = DC_idle ;

	/* Read Input */

	/* Transaction */
	DC_state = STATE(DC_idle);
	printf("DC Idle : speed = %ld\n", speed);
}

STATE_define(DC_busy){
	/* State Action */
	DC_state_id = DC_busy ;

	/* Read Input */

	/* Transaction */
	DC_state = STATE(DC_idle);
	printf("DC Busy : speed = %ld\n", speed);
}

