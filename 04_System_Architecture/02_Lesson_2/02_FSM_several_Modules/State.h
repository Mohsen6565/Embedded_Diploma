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

/* Connections between Modules */
unsigned long US_get_distance(void);
void DC_motor_set_speed(unsigned long spd);


#endif /* STATE_H_ */
