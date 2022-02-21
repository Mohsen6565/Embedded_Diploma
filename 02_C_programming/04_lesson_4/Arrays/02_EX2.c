#include <stdio.h>

int main(){
	float A[100];	/*Assume maximum size of 100 elements*/
	int n, i;
	float avg=0.0;

/*
 * Taking Input from user
 * */
	printf("Enter The Number of Digits: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	for(i=0; i<n; i++){
		printf("%d. Enter a Number: ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%f", &A[i]);
	}

/*
 * Calculating Average
 * */
	for(i=0; i<n; i++){
		avg += A[i];
	}
	avg /= n ;

	printf("Average = %.2f\n", avg);

	return 0;
}
