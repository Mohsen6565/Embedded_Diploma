#include <stdio.h>
#include <string.h>

struct student{
	char name[50];
	int roll;
	int marks;
};

int main(){
	struct student s1;

	printf("Enter Information of Student:\n");
	printf("Enter name: ");
	fflush(stdin); fflush(stdout);
	scanf("%s", s1.name);
	printf("Enter Roll Number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &s1.roll);
	printf("Enter Marks: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &s1.marks);

	printf("\nDisplaying Information\n");
	printf("Name: %s\n", s1.name);
	printf("Roll: %d\n", s1.roll);
	printf("Marks: %d\n", s1.marks);


	return 0;
}

