#include <stdio.h>
#include <stdlib.h>
#include "State.h"

/* Global Variables */
unsigned long CA_distance ;
unsigned long CA_speed ;
unsigned long CA_threshold = 50 ;

/* State ID*/
enum{
	CA_wating,
	CA_driving
}CA_state_id;

/* State Pointer */
void(*CA_state)(void);

/* APIs */
STATE_define(wating);
STATE_define(driving);
long generate_random(long l, long r, long count);

void setup(void){
	CA_threshold = 50 ;
	CA_state = STATE(wating);
}

int main(void){

	setup();
	unsigned long delay ;
	while(1){
		CA_state();
		for(delay=0; delay<=2000; delay++);
	}


	return 0 ;
}

STATE_define(wating){
	/* State Action */
	CA_state_id = CA_wating ;
	CA_speed = 0 ;

	/* Read Inputs */
	CA_distance = generate_random(45, 55, 1);

	/* State Transaction */
	(CA_distance <= 50)?(CA_state = STATE(wating)):(CA_state = STATE(driving));
	printf("Waiting State | CA_speed = %ld | CA_distance = %ld\n", CA_speed, CA_distance);
}

STATE_define(driving){
	/* State Action */
	CA_state_id = CA_driving ;
	CA_speed = 30 ;

	/* Read Inputs */
	CA_distance = generate_random(45, 55, 1);

	/* State Transaction */
	(CA_distance <= 50)?(CA_state = STATE(wating)):(CA_state = STATE(driving));
	printf("Driving State | CA_speed = %ld | CA_distance = %ld\n", CA_speed, CA_distance);
}

long generate_random(long l, long r, long count){
	long i, rand_num ;
	for(i=0; i<count; i++){
		rand_num = (rand() % (r - l + 1)) + l ;
	}
	return (long)rand_num ;
}

