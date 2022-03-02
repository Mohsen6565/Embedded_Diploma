#include <stdio.h>
#include <string.h>

int power(int base, int exp);

int main(){
	int base, exp;


	printf("Enter Base: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &base);
	printf("Enter Power: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &exp);

	printf("%d^%d = %d", base, exp, power(base, exp));

	return 0;
}

int power(int base, int exp){
	int return_value = 1 ;

	if(exp == 0){
		return_value = 1;
	}else{
		return_value = base*power(base, exp-1);
	}

	return return_value;
}
