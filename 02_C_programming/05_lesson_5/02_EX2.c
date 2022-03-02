#include <stdio.h>
#include <string.h>
#include <math.h>

int fact(int num);

int main(){
	int num;

	printf("Enter a positive Integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);

	printf("Factorial of %d is %d\n", num, fact(num));


	return 0;
}

int fact(int num){
	int return_value = 1;
	if(num == 1 || num == 0){
		return_value = 1;
	}else{
		return_value = num*fact(num-1);
	}
	return return_value ;
}
