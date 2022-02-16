#include <stdio.h>

int main(){
	char in_char;
	printf("Enter a character: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &in_char);
	printf("ASCII value of G = %d\n", in_char);

	return 0;
}
