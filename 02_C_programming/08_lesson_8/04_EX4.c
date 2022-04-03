#include <stdio.h>
#include <string.h>

int main(){

	int nums[15];
	int i, max ;

	printf("Input the number of elements to store in the array (max 15) :");
	fflush(stdin); fflush(stdout);
	scanf("%d", &max);

	printf("Input %d elements in the array\n", max);
	for(i=0; i<max; i++){
		printf("element - %d : ", i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d", nums+i);
	}

	printf("----------------------------------\n");
	/*Print in Reverse Order*/
	for(i=max-1; i>=0; i--){
		printf("element - %d : %d\n", i+1, *(nums+i));
	}

	return 0;
}

