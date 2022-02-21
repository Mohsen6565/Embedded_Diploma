#include <stdio.h>

int main(){
/*
 * Assume maximum number of elements = 100
 * */
	int A[100];
	int n, num, loc=-1;
	int i;

/*
 * Taking Input From User
 * */
	printf("Enter The Number of Elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &n);

	printf("Enter The Elements: ");
	for(i=0; i<n; i++){
		fflush(stdin); fflush(stdout);
		scanf("%d", &A[i]);
	}

	printf("Enter The Number to be searched: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);

/*
 * Searching For The Element
 * */
	for(i=0; i<n; i++){
		if(A[i] == num){
			loc = i ;
		}
	}

	if(loc > 0){
		printf("Element found at location: %d", loc+1);
	}else{
		printf("Element isn't  found");
	}


	return 0;
}
