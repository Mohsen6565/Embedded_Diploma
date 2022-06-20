/*
 * CA.c
 *
 *  Created on: Jun 20, 2022
 *      Author: Mohamed Mohsen
 */
#include <stdio.h>
#include <stdlib.h>
#include "US_sensor.h"
#include "DC_motor.h"
#include "CA.h"

extern unsigned long threshold ;


STATE_define(CA_waiting){
	/* State Action */
	CA_state_id = CA_waiting ;
	DC_motor_set_speed(0);

	/* Read Input */
	US_state();

	/* Transaction */
	(distance <= threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("CA Waiting State : \n");
}
STATE_define(CA_driving){
	/* State Action */
	CA_state_id = CA_driving ;
	DC_motor_set_speed(30);

	/* Read Input */
	US_state();

	/* Transaction */
	(distance <= threshold)?(CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
	printf("CA Driving State : \n");

}
