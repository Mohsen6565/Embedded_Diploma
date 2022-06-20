#include <stdlib.h>
#include <stdio.h>
/* Macros */
#define STATE_define(_s_function)	void ST_##_s_function(void)
#define STATE(_s_function)			ST_##_s_function

/* Variables Used by State Machine*/
unsigned long distance, speed, threshold ;
enum {
	waiting,
	driving
}state_id;

/* Prototypes */
STATE_define(waiting);
STATE_define(driving);
long generate_random(long l, long r, long count);
/* State Pointer */
void (*state)(void) ;

/* Setup */
void setup(void){
	/* Initializations */
	threshold = 50 ;
	state = STATE(waiting);
}

int main(void){
	volatile long delay ;
	setup();

	while(1){
		state();
		for(delay=0; delay<=1000; delay++);
	}

	return 0 ;
}

STATE_define(waiting){
	/* State Action */
	state_id = waiting ;
	speed = 0 ;

	/* Read Input */
	distance = generate_random(45, 55, 1);

	/* Transaction step */
	(distance <= threshold) ? (state = STATE(waiting)) : (state = STATE(driving)) ;
	printf("Waiting State | speed = %ld | distance = %ld\n", speed, distance);
}

STATE_define(driving){
	/* State Action */
	state_id = driving ;
	speed = 30 ;

	/* Read Input */
	distance = generate_random(45, 55, 1);

	/* Transaction */
	(distance <= threshold) ? (state = STATE(waiting)) : (state = STATE(driving)) ;
	printf("Driving State | speed = %ld | distance = %ld\n", speed, distance);
}

long generate_random(long l, long r, long count){
	long i, rand_num ;
	for(i=0; i<count; i++){
		rand_num = (rand() % (r - l + 1)) + l ;
	}
	return (long)rand_num ;
}
