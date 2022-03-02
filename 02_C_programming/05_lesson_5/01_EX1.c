#include <stdio.h>
#include <string.h>
#include <math.h>

char is_prime(int num);
void print_primes(int start, int end);

int main(){
	int start, end;

	printf("Enter two numbers(start and end of interval): ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &start, &end);

	printf("Prime Numbers between %d and %d are: ", start, end);
	print_primes(start, end);

	return 0;
}

char is_prime(int num){
	char return_val = 1;
	int i;

	if(num == 0 || num == 1){
		return_val = 0;
	}else{
		for(i=2; i<=(int)sqrt(num) && return_val; i++){
			if(num%i == 0){
				return_val = 0;
			}
		}
	}

	return return_val;
}
void print_primes(int start, int end){
	int i;
	for(i=start; i<=end; i++){
		if(is_prime(i))
			printf("%d ", i);
	}
}
