//#include <stdint.h>
//#include <stdio.h>
#include "driver.h"
#include "pressure_sensor.h"
#include "pressure_detection_controller.h"
#include "alarm.h"

void setup(void){
	PD_pressure_threshold = 20 ;
	PS_state = STATE(PS_reading);
	PD_state = STATE(PD_reading_pressure_value);
	AL_state = STATE(AL_busy);

	PS_init();
	PD_init();
	AL_init();

	GPIO_INITIALIZATION();
}

int main (){

	setup();

	while (1)
	{
		PS_state();
		PD_state();
		AL_state();
		// Set_Alarm_actuator(1);
		// Delay(600);
		// Set_Alarm_actuator(0);
		// Delay(600);
//		printf("==========================================\n");
	}

}
