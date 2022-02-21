#include <stdio.h>

int main(){
	long num1, iter=1 ;

	while(iter <= 2){
		printf("Enter an Integer you want to check: ");
		fflush(stdin); fflush(stdout);
		scanf("%ld", &num1);

		if(num1 % 2 == 0){
			printf("%ld is Even\n", num1);
		}else{
			printf("%ld is Odd\n", num1);
		}
		iter += 1;
	}
	return 0;
}
