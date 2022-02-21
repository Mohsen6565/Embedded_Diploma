#include <stdio.h>

int main(){
	char letter;
	char itr = 1 ;

	for(itr=1; itr<=2; itr++){
		printf("Enter a Character: ");
		fflush(stdin); fflush(stdout);
		scanf("%c", &letter);

		// ASCII Values of alphabets
		if( (letter>=65 && letter<=90) || (letter>=97 && letter<=122) ){
			printf("%c is an Alphabet\n", letter);
		}else{
			printf("%c is not an Alphabet\n", letter);
		}

	}

	return 0;
}
