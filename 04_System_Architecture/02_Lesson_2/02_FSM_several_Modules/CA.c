/*
 * CA.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Mohamed Mohsen
 */
#include "CA.h"

void US_send_distance(unsigned long distance){
	CA_distance = distance ;
	printf("US_distance --> CA_distance\n");
}
void DC_send_speed(unsigned long speed){
	DC_speed = speed ;
	printf("CA_speed --> DC_speed\n");
	DC_state = STATE(DC_busy);
}

STATE_define(CA_waiting){
	/* State Action */
	CA_state_id = CA_waiting ;
	CA_speed = 0 ;
	DC_send_speed(CA_speed);

	/* Reading Inputs */
	US_send_distance(US_distance);

	/* State Transaction */
	(CA_distance <= 50)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("CA Waiting State | CA_speed = %ld | CA_distance = %ld\n", CA_speed, CA_distance);
}

STATE_define(CA_driving){
	/* State Action */
	CA_state_id = CA_driving ;
	CA_speed = 30 ;
	DC_send_speed(CA_speed);

	/* Reading Inputs */
	US_send_distance(US_distance);

	/* State Transaction */
	(CA_distance <= 50)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("CA Driving State | CA_speed = %ld | CA_distance = %ld\n", CA_speed, CA_distance);
}

