#include <stdio.h>

int main(){
/*
 * Assume maximum number of elements = 100
 * */
	int A[100];
	int n, num, loc;
	int i;

/*
 * Taking Input from user
 * */
	printf("Enter The Number of Elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	printf("Enter Elements: ");
	for(i=0; i<n; i++){
		fflush(stdin); fflush(stdout);
		scanf("%d", &A[i]);
	}

/*
 * Solving The Problem
 * */
	printf("Enter The Number to be inserted: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);

	printf("Enter The Location of the number to be inserted: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &loc);

/*
 * Shifting Array
 * */
	for(i=n; i>(loc-1); i--){
		A[i] = A[i-1];
	}

/*
 * Inserting The New Element
 * */
	A[loc-1] = num ;
	n++ ;

/*
 * Printing The New Array
 * */
	for(i=0; i<n; i++){
		printf("%d  ", A[i]);
	}

	return 0;
}
