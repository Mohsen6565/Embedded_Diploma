#include <stdio.h>

int main(){
	float A1[2][2], A2[2][2], A_sum[2][2];
	int i, j;

/*
 * Taking the numbers of the first matrix
 * */
	printf("Enter the elements of the 1st matrix\n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("Enter a%d%d: ", i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &A1[i][j]);
		}
	}
/*
 * Taking the numbers of the second matrix
 */
	printf("Enter the elements of the 2nd matrix\n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("Enter b%d%d: ", i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &A2[i][j]);
		}
	}
/*
 * Calculating The Sum
 */
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			A_sum[i][j] = A1[i][j] + A2[i][j];
		}
	}
/*
 * Printing The Sum Matrix
 */
	printf("Sum of Matrices: \n\n");
	for(i=0; i<2; i++){
		for(j=0; j<2; j++){
			printf("%.1f\t", A_sum[i][j]);
		}
		printf("\n");
	}


	return 0;
}
