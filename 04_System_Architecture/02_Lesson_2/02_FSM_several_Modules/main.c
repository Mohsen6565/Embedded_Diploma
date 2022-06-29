#include <stdio.h>
#include <stdlib.h>
#include "US.h"
#include "CA.h"
#include "DC.h"
#include "State.h"

void setup(void){
	CA_threshold = 50 ;
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);

	US_init();
	DC_init();
}

int main(void){

	setup();
	unsigned long delay ;
	while(1){
		US_state();
		CA_state();
		DC_state();
		printf("=======================================================\n");
		for(delay=0; delay<=2000; delay++);
	}


	return 0 ;
}





