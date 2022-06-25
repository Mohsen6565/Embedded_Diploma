/*
 * US.c
 *
 *  Created on: Jun 25, 2022
 *      Author: Mohamed Mohsen
 */


#include "US.h"
long generate_random(long l, long r, long count);

void US_init(void){
	/* Ultrasonic Initializaion */
	printf("US init\n");
}

STATE_define(US_busy){
	/* State Action */
	US_state_id = US_busy ;

	/* Reading Inputs */
	US_distance = generate_random(45, 55, 1);

	/* State Transaction */
	US_state = STATE(US_busy);
	printf("US Busy State | US_distance = %ld\n", US_distance);
}

long generate_random(long l, long r, long count){
	long i, rand_num ;
	for(i=0; i<count; i++){
		rand_num = (rand() % (r - l + 1)) + l ;
	}
	return (long)rand_num ;
}
