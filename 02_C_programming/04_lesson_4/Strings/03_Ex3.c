#include <stdio.h>
#include <string.h>

int main(){
/*
 * Assume maximum number of characters = 100
 * */
	char str[100];
	int len, i;

/*
 * Taking Input from User
 * */
	printf("Enter a String: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	len = strlen(str);
	i = len-1;

	printf("Reverse String is : ");
	while(i != -1){
		printf("%c", str[i]);
		i--;
	}

	return 0;
}
