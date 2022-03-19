#include <stdio.h>
#include <string.h>

struct student{
	char name[50];
	int roll;
	int marks;
};


int main(){

	struct student s[3];
	int i;

	printf("Enter Information for Students:\n");
	for(i=0; i<2; i++){
		printf("\nEnter Roll Number: ");
		fflush(stdin); fflush(stdout);
		scanf("%d", &s[i].roll);

		printf("Enter Name: ");
		fflush(stdin); fflush(stdout);
		scanf("%s", s[i].name);

		printf("Enter Marks: ");
		fflush(stdin); fflush(stdout);
		scanf("%d", &s[i].marks);
	}

	printf("\nDisplaying Information of Students:\n");
	for(i=0; i<2; i++){
		printf("Information for Roll Number: %d\n", s[i].roll);
		printf("Name: %s\n", s[i].name);
		printf("Marks: %d\n", s[i].marks);
	}

	return 0;
}


