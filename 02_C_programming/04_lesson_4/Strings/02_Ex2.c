#include <stdio.h>
#include <string.h>

int main(){
/*
 * Assume maximum number of characters = 100
 * */
	char str[100];
	int len=0;

/*
 * Taking Input from User
 * */
	printf("Enter a String: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	while(str[len] != 0){
		len++ ;
	}

	printf("Length of String = %d\n", len);


	return 0;
}
