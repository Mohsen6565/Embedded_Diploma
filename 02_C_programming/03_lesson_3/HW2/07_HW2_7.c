#include <stdio.h>

int main(){
	long n, i;
	long long fact=1;
	int iter;

	for(iter=1; iter<=3; iter++){
		printf("Enter an Integer: ");
		fflush(stdin); fflush(stdout);
		scanf("%ld", &n);
		fact = 1;

		if(n == 0){
			fact = 1;
			printf("Factorial = %lld\n", fact);
		}else if(n>=1){
			for(i=1; i<=n; i++){
				fact *= i ;
			}
			printf("Factorial = %lld\n", fact);
		}else{
			printf("Error!!! Factorial of Negative numbers does not exist\n");
		}
	}

	return 0;
}
