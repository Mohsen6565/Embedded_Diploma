/*
 * pressure_detection_controller.c
 *
 *  Created on: Jun 27, 2022
 *      Author: Mohamed Mohsen
 */
#include "pressure_detection_controller.h"
#include "alarm.h"

void PD_init(void){
//	printf("PD init\n");
}

void PS_send_pressure(int p){
	PD_pressure = p ;
	PD_state = STATE(PD_sending_alarm_signal);
//	printf("PS_pressure --> PD_pressure\n");
}

void AL_alarm_get_signal(int sig){
	AL_alarm_sig = sig ;
	(AL_alarm_sig == 1)?(AL_state = STATE(AL_alarm_on)):(AL_state = STATE(AL_alarm_off));
//	printf("PD_alarm_sig --> AL_alarm_sig\n");
}

STATE_define(PD_reading_pressure_value){
	/* State Action */
	PD_state_id = PD_reading_pressure_value ;

	/* Read Input */

	/* State Transaction */
//	PD_state = STATE(PD_sending_alarm_signal);
//	printf("PD Reading Pressure State | PD_pressure = %d\n", PD_pressure);

}

STATE_define(PD_sending_alarm_signal){
	/* State Action */
	PD_state_id = PD_sending_alarm_signal ;
	PD_alarm_sig = (PD_pressure >= PD_pressure_threshold)? (1):(0);
	AL_alarm_get_signal(PD_alarm_sig);

	/* Read Input */

	/* State Transaction */
	PD_state = STATE(PD_reading_pressure_value);
//	printf("PD Sending Alarm Signal State | PD_alarm_on = %d\n", PD_alarm_sig);
}

