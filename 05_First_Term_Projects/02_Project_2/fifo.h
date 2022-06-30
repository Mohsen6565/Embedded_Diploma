/*
 * fifo.h
 *
 *  Created on: Jun 12, 2022
 *      Author: Mohamed Mohsen
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

#define FIFO_DATA_TYPE 	struct S_student

/* FIFO Data Types */
typedef struct{
	unsigned long count ;
	unsigned long length ;
	FIFO_DATA_TYPE* base ;
	FIFO_DATA_TYPE* head ;
	FIFO_DATA_TYPE* tail ;
}FIFO_buff_t;

typedef enum{
	FIFO_no_error,
	FIFO_empty,
	FIFO_not_empty,
	FIFO_full,
	FIFO_not_full,
	FIFO_null
}FIFO_status_t;

/* FIFO APIs */
FIFO_status_t FIFO_enqueue(FIFO_buff_t* fifo, FIFO_DATA_TYPE item);
FIFO_status_t FIFO_dequeue(FIFO_buff_t* fifo, FIFO_DATA_TYPE* item);
FIFO_status_t FIFO_init(FIFO_buff_t* fifo, FIFO_DATA_TYPE* buff, unsigned long length);
FIFO_status_t FIFO_is_full(FIFO_buff_t* fifo);
FIFO_status_t FIFO_is_empty(FIFO_buff_t* fifo);
void FIFO_get_strstatus(FIFO_status_t status);


#endif /* FIFO_H_ */
