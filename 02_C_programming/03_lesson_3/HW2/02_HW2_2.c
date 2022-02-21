#include <stdio.h>

int main(){
	char alpha, iter=1 ;

	while(iter <= 2){
		printf("Enter an Alphabet: ");
		fflush(stdin); fflush(stdout);
		scanf("%c", &alpha);

		switch(alpha){
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U':
				printf("\"%c\" is a Vowel\n", alpha);
				break;
			default:
				printf("\"%c\" is a Consonant\n", alpha);
		}
		iter += 1;

	}
	return 0;
}
