/*
 * fifo.c
 *
 *  Created on: Jun 12, 2022
 *      Author: Mohamed Mohsen
 */
#include "fifo.h"
#include "types.h"

FIFO_status_t FIFO_is_empty(FIFO_buff_t* fifo){
	/*
	 * 1) Check if buffer exists
	 * 2) Check if count == 0
	 * */
	if(!fifo || !fifo->base || !fifo->head || !fifo->tail){
		return FIFO_null ;
	}
	if(fifo->count == 0){
		return FIFO_empty ;
	}else{
		return FIFO_not_empty ;
	}
}

FIFO_status_t FIFO_is_full(FIFO_buff_t* fifo){
	/*
	 * 1) Check if buffer exists
	 * 2) Check if count == length
	 * */
	if(!fifo || !fifo->base || !fifo->head || !fifo->tail){
		return FIFO_null ;
	}
	if(fifo->count == fifo->length){
		return FIFO_full ;
	}else{
		return FIFO_not_full ;
	}
}

FIFO_status_t FIFO_init(FIFO_buff_t* fifo, FIFO_DATA_TYPE* buff, unsigned long length){
	fifo->base = buff ;
	fifo->head = buff ;
	fifo->tail = buff ;
	fifo->length = length ;
	fifo->count = 0 ;

	if(fifo->base && fifo->length){
		return FIFO_no_error ;
	}else{
		return FIFO_null ;
	}
}

FIFO_status_t FIFO_enqueue(FIFO_buff_t* fifo, FIFO_DATA_TYPE item){
	/*
	 * 1) Check if fifo exists
	 * 2) Check if fifo is full
	 * 3) Add data
	 * */
	if(!fifo || !fifo->base || !fifo->head || !fifo->tail){
		return FIFO_null ;
	}
	if(FIFO_is_full(fifo) == FIFO_full){
		return FIFO_null ;
	}

	*(fifo->head) = item ;
	fifo->count ++ ;
	if(fifo->base+(fifo->length-1) == fifo->head){
		fifo->head = fifo->base ;
	}else{
		fifo->head ++ ;
	}
	return FIFO_no_error ;
}

FIFO_status_t FIFO_dequeue(FIFO_buff_t* fifo, FIFO_DATA_TYPE* item){
	/*
	 * 1) Check if fifo exists
	 * 2) Check if fifo is empty
	 * 3) pop data
	 * */
	if(!fifo || !fifo->base || !fifo->head || !fifo->tail){
		return FIFO_null ;
	}
	if(FIFO_is_empty(fifo) == FIFO_empty){
		return FIFO_null ;
	}
	*(item) = *(fifo->tail);
	fifo->count -- ;
	if(fifo->base+(fifo->length-1) == fifo->tail){
		fifo->tail = fifo->base ;
	}else{
		fifo->tail ++ ;
	}

	return FIFO_no_error ;
}
void FIFO_get_strstatus(FIFO_status_t status){
	switch(status){
		case FIFO_no_error:
			printf("FIFO_no_error");
		break ;
		case FIFO_empty:
			printf("FIFO_empty");
		break ;
		case FIFO_not_empty:
			printf("FIFO_not_empty");
		break ;
		case FIFO_full:
			printf("FIFO_full");
		break ;
		case FIFO_not_full:
			printf("FIFO_not_full");
		break ;
		case FIFO_null:
			printf("FIFO_null");
		break ;
	}
}
