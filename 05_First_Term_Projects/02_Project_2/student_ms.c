/*
 * student_ms.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Mohamed
 */
#include "student_ms.h"

int SM_roll_exists(int r){
	S_student* temp = S_student_FIFO.head ;
	int return_value = 0 ;
	for(int i=0; i<S_student_FIFO.length; i++){
		if(temp == (S_student_FIFO.base + S_student_FIFO.length - 1)){
			temp = S_student_FIFO.base ;
		}else{
			temp ++ ;
		}
		if(temp->roll == r){
			return_value = 1 ;
		}
	}

	return return_value ;
}

void SM_add_student_manually(FIFO_buff_t* fifo, FIFO_DATA_TYPE item){
	/* Check if we can add one more student ******************* */
	/* Check if the roll number is duplicated ******************* */
	if(SM_roll_exists(item.roll)){
		printf("[ERROR] Repeated Roll Number\n");
	}else{
		FIFO_enqueue(fifo,  item);
		printf("[INFO] Student Details are added successfully\n");
		printf("------------------------------------\n");
		printf("[INFO] Total Number of Students: %ld\n", fifo->count);
		printf("[INFO] You can add up to %ld Students\n", fifo->length);
		printf("[INFO] You can add %ld more Students\n", fifo->length - fifo->count);
	}

}

void SM_add_student_file(void){

}

void SM_show(FIFO_buff_t* fifo){
	FIFO_DATA_TYPE* temp = fifo->tail ;
	for(int i=0; i<fifo->count; i++){
		printf("=====================================================\n");
		printf("Roll Number: %d\n", temp->roll);
		printf("First Name: %s\n", temp->first_name);
		printf("Last Name: %s\n", temp->last_name);
		printf("GPA: %f\n", temp->gpa);
		for(int j=1; j<=5; j++){
			printf("Course %d ID:%d \n", j, temp->course_id[j-1]);
		}
		if( temp == (fifo->base + fifo->length - 1)){
			temp = fifo->base ;
		}else{
			temp ++ ;
		}
	}
}

void SM_get_detail_roll(FIFO_buff_t* fifo, int roll_n){
	FIFO_DATA_TYPE* temp = fifo->tail ;
	int j = -1 ;
	printf("======= Roll Number = %d =======\n", roll_n);
	for(int i=0; i<fifo->count; i++){
		if(temp->roll == roll_n){
			printf("=====================================================\n");
			printf("Roll Number: %d\n", temp->roll);
			printf("First Name: %s\n", temp->first_name);
			printf("Last Name: %s\n", temp->last_name);
			printf("GPA: %f\n", temp->gpa);
			for(j=1; j<=5; j++){
				printf("Course %d ID:%d \n", j, temp->course_id[j-1]);
			}
		}
		if(temp == (fifo->base + fifo->length - 1 - 1)){
			temp = fifo->base ;
		}else{
			temp ++ ;
		}
	}
	if(j == -1){
		printf("[ERROR] Roll Number Not Found!\n");

	}
}

void SM_get_detail_f_name(FIFO_buff_t* fifo, char f_name[]){
	FIFO_DATA_TYPE* temp = fifo->tail ;
	int j = -1 ;
	printf("======= First Name = %s =======\n", f_name);
	for(int i=0; i<fifo->count; i++){
		if(strcmp(temp->first_name, f_name) == 0){
			printf("=====================================================\n");
			printf("Roll Number: %d\n", temp->roll);
			printf("First Name: %s\n", temp->first_name);
			printf("Last Name: %s\n", temp->last_name);
			printf("GPA: %f\n", temp->gpa);
			for(j=1; j<=5; j++){
				printf("Course %d ID:%d \n", j, temp->course_id[j-1]);
			}
		}
		if(temp == (fifo->base + fifo->length - 1)){
			temp = fifo->base ;
		}else{
			temp ++ ;
		}
	}
	if(j == -1){
		printf("[ERROR] First Name Not Found!\n");

	}
}

void SM_get_getail_course_id(FIFO_buff_t* fifo, int course_n){
	FIFO_DATA_TYPE* temp = fifo->tail ;
	int j = -1 ;
	printf("======= Course ID = %d =======\n", course_n);
	for(int i=0; i<fifo->count; i++){
		for(int k=0; k<5; k++){
			if(temp->course_id[k] == course_n){
				printf("=====================================================\n");
				printf("Roll Number: %d\n", temp->roll);
				printf("First Name: %s\n", temp->first_name);
				printf("Last Name: %s\n", temp->last_name);
				printf("GPA: %f\n", temp->gpa);
				for(j=1; j<=5; j++){
					printf("Course %d ID:%d \n", j, temp->course_id[j-1]);
				}
			}
		}
		if(temp == (fifo->base + fifo->length - 1)){
			temp = fifo->base ;
		}else{
			temp ++ ;
		}
	}
	if(j == -1){
		printf("[ERROR] Course ID Not Found!\n");

	}
}

unsigned long SM_get_student_count(FIFO_buff_t* fifo){
	return fifo->count ;
}

void SM_delete_roll(FIFO_buff_t* fifo, int roll_n){
	FIFO_DATA_TYPE* temp = fifo->tail ;
	FIFO_DATA_TYPE* roll_ptr = NULL  /* ((void*)0)*/ ;
	for(int i=1; i<=fifo->count; i++){
		if(temp->roll == roll_n){
			roll_ptr = temp ;
		}
		if(temp == (fifo->base + fifo->length - 1)){
			temp = fifo->base ;
		}else{
			temp ++ ;
		}
	}

	temp = roll_ptr + 1 ;
	if(temp > (fifo->base + fifo->length - 1)){
		temp = fifo->base ;
	}
	while(temp != fifo->head){

		*((FIFO_DATA_TYPE*)(roll_ptr)) = *((FIFO_DATA_TYPE*)(temp)) ;

		if(temp == (fifo->base + fifo->length - 1)){
			temp = fifo->base ;
		}else{
			temp ++ ;
		}
		if(roll_ptr == (fifo->base + fifo->length - 1)){
			roll_ptr = fifo->base ;
		}else{
			roll_ptr ++ ;
		}

	}
	*((FIFO_DATA_TYPE*)(roll_ptr)) = *((FIFO_DATA_TYPE*)(temp)) ;
	fifo->head = roll_ptr;
	fifo->count -- ;

}

void SM_update_roll(FIFO_buff_t* fifo, int roll_n, FIFO_DATA_TYPE item){
	FIFO_DATA_TYPE* temp = fifo->tail ;
	FIFO_DATA_TYPE* roll_ptr = NULL  /* ((void*)0)*/ ;
	for(int i=1; i<=fifo->count; i++){
		if(temp->roll == roll_n){
			roll_ptr = temp ;
		}
		if(temp == (fifo->base + fifo->length - 1)){
			temp = fifo->base ;
		}else{
			temp ++ ;
		}
	}

	if(roll_ptr == NULL){
		printf("[ERROR] Roll Number Not Found\n");
	}else if(SM_roll_exists(item.roll)){
		printf("[ERROR] Repeated Roll Number\n");
	}else{
		*((FIFO_DATA_TYPE*)(roll_ptr)) = item ;
	}

}
