#include <stdio.h>

int main(){
	float num1, num2, num3, max;

	printf("Enter three numbers: ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f %f", &num1, &num2, &num3);

	max = (num1>num2)?( (num1>num3)?num1:num3 ):( (num2>num3)?num2:num3 );
	printf("Largest Number = %f", max);

	return 0;
}
