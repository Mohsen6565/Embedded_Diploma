#include <stdio.h>
#include <string.h>

int main(){
/*
 * Assume maximum number of characters = 100
 * */
	char str[100];
	char character;
	int i, freq=0;

/*
 * Taking Input from User
 * */
	printf("Enter a String: ");
	fflush(stdin); fflush(stdout);
	gets(str);

	printf("Enter a character to find Frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &character);

/*
 * Finding The Frequency
 * */
	i = 0;
	while(str[i] != 0){
		if(str[i] == character){
			freq++ ;
		}
		i++ ;
	}

	printf("Frequency of %c: %d\n", character, freq);

	return 0;
}
