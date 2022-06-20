/*
 * US_sensor.c
 *
 *  Created on: Jun 20, 2022
 *      Author: Mohamed Mohsen
 */
#include <stdio.h>
#include <stdlib.h>
#include "State.h"
#include "US_sensor.h"

void US_init(void){
	/* Initialization of Ultrasonic Sensor */
	printf("Ultrasonic Sensor Initialized !\n");
}

unsigned long US_get_distance(void){
	unsigned long distance ;
	distance = generate_random(45, 55, 1);
	return distance ;
}

STATE_define(US_busy){
	/* State Action */
	US_state_id = US_busy ;

	/* Read Input */
	distance = US_get_distance();

	/* Transaction */
	US_state = STATE(US_busy) ;
	printf("US Busy State : distance = %ld\n", distance);
}

static unsigned long generate_random(long l, long r, long count){
	unsigned long i, rand_num ;
	for(i=0; i<count; i++){
		rand_num = (rand() % (r - l + 1)) + l ;
	}
	return (unsigned long)rand_num ;
}
