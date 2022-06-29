/*
 * State.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef STATE_H_
#define STATE_H_

/* Macros */
#define STATE_define(_s_function)	void ST_##_s_function(void)
#define STATE(_s_function)			ST_##_s_function

/* Intermediate Signals */
void PS_send_pressure(int p);
void AL_alarm_get_signal(int sig);


#endif /* STATE_H_ */
