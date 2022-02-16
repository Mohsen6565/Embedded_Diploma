#include <stdio.h>

int main(){
	float num1, num2;
	printf("Enter value of num1: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &num1);
	printf("Enter value of num2: ");
	fflush(stdin); fflush(stdout);
	scanf("%f", &num2);

	num1 = num1 + num2 ;
	num2 = num1 - num2 ;
	num1 = num1 - num2 ;

	printf("After swapping, value of num1 = %f\n", num1);
	printf("After swapping, value of num2 = %f\n", num2);

	return 0;
}
