/*
 * lifo.h
 *
 *  Created on: Jun 12, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdlib.h>

/* Data Types */
typedef struct{
	unsigned long length ;
	unsigned long count ;
	unsigned char* base ;
	unsigned char* head ;
}LIFO_buff_t;

typedef enum{
	LIFO_no_error,
	LIFO_empty,
	LIFO_not_empty,
	LIFO_full,
	LIFO_not_full,
	LIFO_null
}LIFO_status_t;

/* Functions Prototype */

LIFO_status_t LIFO_is_full(LIFO_buff_t* buff);
LIFO_status_t LIFO_is_empty(LIFO_buff_t* buff);
void LIFO_get_strstatus(LIFO_status_t status);
LIFO_status_t LIFO_push(LIFO_buff_t* buff, unsigned char item);
LIFO_status_t LIFO_pop(LIFO_buff_t* buff, unsigned char* item);


#endif /* LIFO_H_ */
