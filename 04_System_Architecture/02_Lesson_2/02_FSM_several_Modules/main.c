#include <stdio.h>
#include <stdlib.h>
#include "US_sensor.h"
#include "DC_motor.h"
#include "CA.h"

unsigned long distance , speed , threshold ;

void setup(void){
	US_init();
	DC_init();
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
	threshold = 50 ;
}

int main(void){

	setup();
	volatile unsigned long d ;

	while(1){

		CA_state();
		for(d=0; d<=2000; d++);
	}

	return 0 ;
}
