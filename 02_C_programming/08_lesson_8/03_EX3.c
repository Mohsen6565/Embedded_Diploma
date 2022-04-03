#include <stdio.h>
#include <string.h>

int main(){

	char str[50], temp;
	char *ptr_str = str ;
	int i, length;

	printf("Enter a String: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	length = strlen(str);

	for(i=0; i<length/2; i++){
		temp = *(ptr_str + i);
		*(ptr_str + i) = *(ptr_str + length - 1 - i);
		*(ptr_str + length - 1 - i) = temp ;
	}

	printf("Reversed String is : %s ", str);

	return 0;
}

