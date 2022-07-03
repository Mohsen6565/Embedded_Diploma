/*
 * main.c
 *
 *  Created on: Jun 29, 2022
 *      Author: Mohamed
 */
#include <stdio.h>
#include <stdlib.h>
#include "student_ms.h"

int get_user_choice(void);

int main(){
	
	FIFO_init(&S_student_FIFO, S_students_buff, 50);
	int choice = 0 ;
	int num ;
	char f_name[50];
	char file_path[255] = "data.txt";

	printf("Welcome To The Student Management System\n");
	do{
		choice = get_user_choice() ;
		switch(choice){
		case 1:{
			/* Add Student Data Manually */
			FIFO_DATA_TYPE item ;
			printf("--------------------------------\n");
			printf("Add the student details\n");
			printf("--------------------------------\n");
			printf("Enter The Roll Number: ");
			fflush(stdin); fflush(stdout);
			scanf("%d", &(item.roll));

			printf("Enter The First Name: ");
			fflush(stdin); fflush(stdout);
			gets(item.first_name);

			printf("Enter The Last Name: ");
			fflush(stdin); fflush(stdout);
			gets(item.last_name);

			printf("Enter The GPA: ");
			fflush(stdin); fflush(stdout);
			scanf("%f", &(item.gpa));

			printf("Enter The Course ID of each Course: \n");
			for(int i=1; i<=5; i++){
				printf("Course %d ID: ", i);
				fflush(stdin); fflush(stdout);
				scanf("%d", &(item.course_id[i-1]));
			}

			SM_add_student_manually(&S_student_FIFO, item);

		}break;
		case 2:{
			/* Add Student Data from a file */
			printf("Enter File Path: ");
			fflush(stdin); fflush(stdout);
			gets(file_path);
			SM_add_student_file(&S_student_FIFO, file_path);
		}break;
		case 3:{
			/* Get Student Details by Roll Number */
			printf("--------------------------------\n");
			printf("Enter Roll Number: ");
			fflush(stdin); fflush(stdout);
			scanf("%d", &num);
			SM_get_detail_roll(&S_student_FIFO, num);
		}break;
		case 4:{
			/* Get Student Details by First Name */
			printf("--------------------------------\n");
			printf("Enter First Name: ");
			fflush(stdin); fflush(stdout);
			gets(f_name);
			SM_get_detail_f_name(&S_student_FIFO, f_name);
		}break;
		case 5:{
			/* Get Students' Details by course Number */
			printf("--------------------------------\n");
			printf("Enter Course Number: ");
			fflush(stdin); fflush(stdout);
			scanf("%d", &num);
			SM_get_detail_course_id(&S_student_FIFO, num);
		}break;
		case 6:{
			/* Get Total Number of Students */
			printf("--------------------------------\n");
			printf("Total Number of Students is: %ld\n", SM_get_student_count(&S_student_FIFO));
		}break;
		case 7:{
			/* Delete Student Details Using Roll Number*/
			printf("--------------------------------\n");
			printf("Enter Roll Number: ");
			fflush(stdin); fflush(stdout);
			scanf("%d", &num);
			SM_delete_roll(&S_student_FIFO, num);
		}break;
		case 8:{
			/* Update Student Details Using Roll Number*/
			FIFO_DATA_TYPE item ;
			printf("Enter Roll Number:");
			fflush(stdin); fflush(stdout);
			scanf("%d", &num);

			printf("--------------------------------\n");
			printf("Add the student details\n");
			printf("--------------------------------\n");
			printf("Enter The Roll Number: ");
			fflush(stdin); fflush(stdout);
			scanf("%d", &(item.roll));

			printf("Enter The First Name: ");
			fflush(stdin); fflush(stdout);
			gets(item.first_name);

			printf("Enter The Last Name: ");
			fflush(stdin); fflush(stdout);
			gets(item.last_name);

			printf("Enter The GPA: ");
			fflush(stdin); fflush(stdout);
			scanf("%f", &(item.gpa));

			printf("Enter The Course ID of each Course: \n");
			for(int i=1; i<=5; i++){
				printf("Course %d ID: ", i);
				fflush(stdin); fflush(stdout);
				scanf("%d", &(item.course_id[i-1]));
			}
			SM_update_roll(&S_student_FIFO, num, item);

		}break;
		case 9:{
			/* Show all information */
			SM_show(&S_student_FIFO);

		}break;
		}
	}while(choice != 10);

	return 0 ;
}

int get_user_choice(void){
	int return_value = 0 ;
	printf("=====================================================\n");
	printf("Choose The Task you want to perform\n");
	printf("1) Add Student Data Manually\n");
	printf("2) Add Student Data From a Text File\n");
	printf("3) Get Student Details by Roll Number\n");
	printf("4) Get Student Details by First Name\n");
	printf("5) Get Students\' Details by Course Number\n");
	printf("6) Get Total Number of Students\n");
	printf("7) Delete The Student Details by Roll Number\n");
	printf("8) Update The Student Details by Roll Number\n");
	printf("9) Show all information\n");
	printf("10) To Exit\n");
	printf("Enter Your Choice To Perform The Task: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &return_value);

	return return_value ;
}
