/*
 * student_ms.h
 *
 *  Created on: Jun 29, 2022
 *      Author: Mohamed
 */

#ifndef STUDENT_MS_H_
#define STUDENT_MS_H_

#include "fifo.h"
#include "types.h"
#include <string.h>
#include <stdlib.h>

/* Students */
FIFO_buff_t S_student_FIFO ;
S_student S_students_buff[50];

/* API */
int SM_roll_exists(int r);
void SM_add_student_manually(FIFO_buff_t* fifo, FIFO_DATA_TYPE item);
void SM_add_student_file(void);
void SM_get_detail_roll(FIFO_buff_t* fifo, int roll_n);
void SM_get_detail_f_name(FIFO_buff_t* fifo, char f_name[]);
void SM_get_getail_course_id(FIFO_buff_t* fifo, int course_n);
unsigned long SM_get_student_count(FIFO_buff_t* fifo);
void SM_delete_roll(FIFO_buff_t* fifo, int roll_n);
void SM_update_roll(FIFO_buff_t* fifo, int roll_n, FIFO_DATA_TYPE item);
void SM_show(FIFO_buff_t* fifo);


#endif /* STUDENT_MS_H_ */
