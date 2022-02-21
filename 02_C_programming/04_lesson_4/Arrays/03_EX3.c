#include <stdio.h>

int main(){
	/*
	 * Assume maximum size of 50x50 elements
	 * */
	int A[50][50];
	int m, n, i, j;

	/*
	 * Taking Input from The User
	 * */
	printf("Enter The Number of Rows: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &m);

	printf("Enter The Number of Columns: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("Enter a%d%d: ", i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d", &A[i][j]);
		}
	}

	/*
	 * Printing Entered Matrix
	 * */
	printf("Enter Matrix: \n");
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}

	/*
	 * Printing Transposed Matrix
	 * */
	printf("Transpose Matrix: \n");
	for(j=0; j<n; j++){
		for(i=0; i<m; i++){
			printf("%d\t", A[i][j]);
		}
		printf("\n");
	}

	return 0;
}
