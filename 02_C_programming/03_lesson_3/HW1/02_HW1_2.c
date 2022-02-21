#include <stdio.h>

int main(){
	long number ;
	printf("Enter an Integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%ld", &number);
	printf("You Entered: %ld", number);

	return 0;
}
