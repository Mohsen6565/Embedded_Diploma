#include <stdio.h>

int main(){
	long num1, num2;
	printf("Enter two Integers: ");
	fflush(stdin); fflush(stdout);
	scanf("%ld %ld", &num1, &num2);
	printf("Sum: %ld\n", num1+num2);

	return 0;
}
