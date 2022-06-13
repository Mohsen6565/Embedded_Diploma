/*
 * lifo.c
 *
 *  Created on: Jun 12, 2022
 *      Author: Mohamed Mohsen
 */
#include "lifo.h"

LIFO_status_t LIFO_is_full(LIFO_buff_t* buff){
	if(buff->count == buff->length){
		return LIFO_full ;
	}else{
		return LIFO_not_full ;
	}
}

LIFO_status_t LIFO_is_empty(LIFO_buff_t* buff){
	if(buff->count == 0){
		return LIFO_empty ;
	}else{
		return LIFO_not_empty ;
	}
}

LIFO_status_t LIFO_push(LIFO_buff_t* buff, unsigned char item){
	/* 1) Check if the LIFO exists */
	/* 2) Check if LIFO is full */

	/* 1) Check if the LIFO exists */
	/* base != NULL */
	if(!buff || !buff->base || !buff->head){
		return LIFO_null ;
	}
	/* 2) Check if LIFO is full */
	if(LIFO_is_full(buff) == LIFO_full){
		return LIFO_null ;
	}

	/* Add the item */
	*(buff->head) = item ;
	buff->head ++ ;
	buff->count ++ ;

	return LIFO_no_error ;
}

LIFO_status_t LIFO_pop(LIFO_buff_t* buff, unsigned char* item){
	/* 1) Check if LIFO exists */
	/* 2) Check if LIFO is empty */

	/* 1) Check if the LIFO exists */
	/* base != NULL */
	if(!buff || !buff->base || !buff->head){
		return LIFO_null ;
	}

	/* 2) Check if LIFO is empty */
	if(LIFO_is_empty(buff) == LIFO_empty){
		return LIFO_null ;
	}

	buff->head -- ;
	*item = *(buff->head);
	buff->count -- ;

	return LIFO_no_error ;

}

void LIFO_get_strstatus(LIFO_status_t status){
	switch(status){
		case LIFO_no_error:
			printf("LIFO_no_error");
		break ;
		case LIFO_empty:
			printf("LIFO_empty");
		break ;
		case LIFO_not_empty:
			printf("LIFO_not_empty");
		break ;
		case LIFO_full:
			printf("LIFO_full");
		break ;
		case LIFO_not_full:
			printf("LIFO_not_full");
		break ;
		case LIFO_null:
			printf("LIFO_null");
		break ;
	}
}
