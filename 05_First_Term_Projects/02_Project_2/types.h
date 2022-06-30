/*
 * types.h
 *
 *  Created on: Jun 29, 2022
 *      Author: Mohamed
 */

#ifndef TYPES_H_
#define TYPES_H_

#define FIFO_DATA_TYPE 	struct S_student

typedef struct S_student{
	char first_name[50];
	char last_name[50];
	int roll ;
	float gpa ;
	int course_id[5] ;
}S_student;


#endif /* TYPES_H_ */
