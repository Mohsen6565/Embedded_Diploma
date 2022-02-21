#include <stdio.h>

int main(){
	float num;
	char itr = 1 ;

	for(itr=1; itr<=3; itr++){
		printf("Enter a Number: ");
		fflush(stdin); fflush(stdout);
		scanf("%f", &num);
		if(num > 0){
			printf("%f is Positive\n", num);
		}else if(num < 0){
			printf("%f is Negative\n", num);
		}else{
			printf("You Entered a Zero\n");
		}
	}

	return 0;
}
