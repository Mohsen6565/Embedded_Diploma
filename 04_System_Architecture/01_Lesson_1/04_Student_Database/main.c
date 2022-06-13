#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

typedef S_node	S_student ;
unsigned char user_choices(void);
unsigned long get_student_index(S_student* s1_head, unsigned long id);

int main(){
	unsigned char choice ;
	unsigned long id_deleted ;
	unsigned long indx_id_deleted;
	unsigned long list_length ;
	S_student* s_head = NULL ;
	S_student* data_entry = NULL ;

	do{
		choice = user_choices();
		switch(choice){
		case 1:
		{
			data_entry = (S_student*)malloc(1*sizeof(S_student));
			printf("Enter Student ID: ");
			fflush(stdin);fflush(stdout);
			scanf("%ld", &data_entry->id);

			printf("Enter Student Full Name: ");
			fflush(stdin);fflush(stdout);
			gets(data_entry->name);

			printf("Enter Student Height: ");
			fflush(stdin);fflush(stdout);
			scanf("%ld", &data_entry->height);

			data_entry->next_ptr = NULL ;		/* To avoid segmentation fault when using LL_append*/

			if(s_head == NULL){
				s_head = data_entry ;
			}else{
				LL_append(&s_head, data_entry);
			}
		}
		break;
		case 2:
		{
			printf("Enter Student ID to be deleted: ");
			fflush(stdin);fflush(stdout);
			scanf("%ld", &id_deleted);
			indx_id_deleted = get_student_index(s_head, id_deleted) ;
			LL_remove(&s_head, indx_id_deleted);
		}
		break;
		case 3:
		{
			LL_print(s_head);
		}
		break;
		case 4:
		{
			while(s_head){
				LL_remove(&s_head, 0);
			}
			s_head = NULL ;
		}
		break;
		default:
			printf("Please enter one of the following numbers (1, 2, 3, 4)\n");
			break ;
		}
	}while(1);


	return 0;
}

unsigned char user_choices(void){
	unsigned char choice ;

	printf("=====================================================\n");
	printf("Choose one of the following options: \n\n");
	printf("\t1)Add Student\n");
	printf("\t2)Delete Student\n");
	printf("\t3)View All Students\n");
	printf("\t4)Delete all Students\n");
	printf("\n");
	printf("Enter Option Number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &choice);
	printf("\n=====================================================\n");

	return choice ;
}
unsigned long get_student_index(S_student* s1_head, unsigned long id){
	long indx =  0;
	char flag = 1 ;
	while(s1_head && flag){
		if(s1_head->id == id){
			flag = 0 ;
		}else{
			indx ++ ;
		}
		s1_head = s1_head->next_ptr ;
	}
	if(flag){
		indx = -1 ;
	}
	return indx ;
}
