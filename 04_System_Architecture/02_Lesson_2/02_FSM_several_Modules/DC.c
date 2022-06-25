/*
 * DC.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Mohamed Mohsen
 */
#include "DC.h"

void DC_init(void){
	/* DC motor Initializaion */
	printf("DC init\n");
}

STATE_define(DC_idle){
	/* State Action */
	DC_state_id = DC_idle ;
	// Sending DC_speed to Motor function of interfacing stage

	/* Read Input */

	/* State Transaction*/
	DC_state = STATE(DC_idle);
	printf("DC Idle State | DC_speed = %ld\n", DC_speed);
}

STATE_define(DC_busy){
	/* State Action */
	DC_state_id = DC_busy ;

	/* Read Input */

	/* State Transaction*/
	DC_state = STATE(DC_idle);
	printf("DC Busy State | DC_speed = %ld\n", DC_speed);
}
