#include <stdio.h>

int main(){
	long n;
	long long sum=0;

	printf("Enter an Integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%ld", &n);

	sum = (n+1)*(n)/2 ;

	printf("Sum = %lld\n", sum);

	return 0;
}
