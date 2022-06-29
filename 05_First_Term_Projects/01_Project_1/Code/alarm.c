/*
 * alarm.c
 *
 *  Created on: Jun 27, 2022
 *      Author: Mohamed Mohsen
 */
#include "alarm.h"

void AL_init(void){
//	printf("AL init\n");
}
void AL_turn_on(void){
	Set_Alarm_actuator(0);
}
void AL_turn_off(void){
	Set_Alarm_actuator(1);
}
STATE_define(AL_busy){
	/* State Action */
	AL_state_id = AL_busy ;

	/* Read Inputs */

	/* State Transaction */
	// printf("AL Busy State | AL_alarm_sig = %d\n", AL_alarm_sig);

}
STATE_define(AL_alarm_on){
	/* State Action */
	AL_state_id = AL_alarm_on ;
	AL_turn_on();
	Delay(600);

	/* Read Inputs */

	/* State Transaction */
	AL_state = STATE(AL_busy);
//	printf("AL alarm on State | AL_alarm_sig = %d\n", AL_alarm_sig);

}
STATE_define(AL_alarm_off){
	/* State Action */
	AL_state_id = AL_alarm_off ;
	AL_turn_off();

	/* Read Inputs */

	/* State Transaction */
	AL_state = STATE(AL_busy);
//	printf("AL alarm off State | AL_alarm_sig = %d\n", AL_alarm_sig);

}

