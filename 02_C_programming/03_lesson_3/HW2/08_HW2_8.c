#include <stdio.h>

int main(){
	char operator;
	float num1, num2, result;
	int iter;

	for(iter=1; iter<=5; iter++){
		printf("Enter an Operator ( + , - , * , / ): ");
		fflush(stdin); fflush(stdout);
		scanf("%c", &operator);
		printf("Enter two numbers: ");
		fflush(stdin); fflush(stdout);
		scanf("%f %f", &num1, &num2);
		result = 0;

		switch(operator){
		case '+':
		{
			result = num1 + num2;
			printf("%f + %f = %f\n", num1, num2, result);
			break;
		}
		case '-':
		{
			result = num1 - num2;
			printf("%f - %f = %f\n", num1, num2, result);
			break;
		}
		case '*':
		{
			result = num1 * num2;
			printf("%f * %f = %f\n", num1, num2, result);
			break;
		}
		case '/':
		{
			if(num2 != 0.0){
				result = num1 / num2;
				printf("%f / %f = %f\n", num1, num2, result);
			}else{
				printf("Can not divide by zero!\n");
			}
			break;
		}

		}
	}



	return 0;
}
