/*
 * pressure_sensor.c
 *
 *  Created on: Jun 27, 2022
 *      Author: Mohamed Mohsen
 */
#include "pressure_sensor.h"
//#include "stdlib.h"

void PS_init(void){
//	printf("PS init\n");
}

//long generate_random(long l, long r, long count){
//	long i, rand_num ;
//	for(i=0; i<count; i++){
//		rand_num = (rand() % (r - l + 1)) + l ;
//	}
//	return (long)rand_num ;
//}

STATE_define(PS_reading){
	/* State Action */
	PS_state_id = PS_reading ;

	/* Read Input */
	PS_pressure = getPressureVal();
//	PS_pressure = generate_random(19, 21, 1);

	/* State Transaction */
	PS_state = STATE(PS_sending);
//	printf("PS Reading State | PS_pressure = %d\n", PS_pressure);

}

STATE_define(PS_sending){
	/* State Action */
	PS_state_id = PS_sending ;
	PS_send_pressure(PS_pressure);
	Delay(3);

	/* Read Input */

	/* State Transaction */
	PS_state = STATE(PS_idle);
//	printf("PS Sending State | PS_pressure = %d\n", PS_pressure);
}

STATE_define(PS_idle){
	/* State Action */
	PS_state_id = PS_idle ;

	/* Read Input */

	/* State Transaction */
	PS_state = STATE(PS_reading);
//	printf("PS Idle State\n");

}

