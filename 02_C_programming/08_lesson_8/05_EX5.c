#include <stdio.h>
#include <string.h>

typedef struct Semployee_stru{
	char name[50];
	int id ;
}Semployee;

int main(){

	int i;

	Semployee emp_1 = {"Hammad", 123};
	Semployee emp_2 = {"Akram", 456};
	Semployee emp_3 = {"Sayed", 789};

	Semployee *emp_arr[3] = {&emp_1, &emp_2, &emp_3};
	Semployee (*(*ptr)[3]) = &emp_arr;

/*	printf("%s \t %d\n", emp_arr[0]->name, emp_arr[0]->id); */

	/*
		printf("ptr = %d \t\t ptr+1=%d \t\t ptr+2=%d\n", ptr, ptr+1, ptr+2);
		printf("*ptr = %d \t\t *(ptr)+1=%d \t *(ptr)+2=%d\n", *ptr, *(ptr)+1, *(ptr)+2);
		printf("&emp_1 = %d \t &emp_2 = %d \t &emp_3 = %d\n", &emp_1, &emp_2, &emp_3);
		printf("**(ptr) = %d \t *(*(ptr)+1)=%d \t *(*(ptr)+2)=%d\n", **(ptr), *(*(ptr)+1), *(*(ptr)+2));
	*/

	/*Notes
	 *
	 * Remember to add parentheses ()
	 * *(*(ptr)+0)->name		Wrong	Error
	 * (*(*(ptr)+0))->name 		Correct
	 *
		printf("*(*(ptr)+0)->name = %s\n", (*(*(ptr)+0))->name);
		printf("*(*(ptr)+0)->id = %d\n", (*(*(ptr)+0))->id);
	*/

	for(i=0; i<3; i++){
		printf("Name : %s \t ID : %d\n", (*(*(ptr)+i))->name, (*(*(ptr)+i))->id);
	}


	return 0;
}

