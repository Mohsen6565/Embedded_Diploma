#include <stdio.h>
#include <string.h>

int main(){

	int i=0 ;
	char alpha[26];
	char *ptr_alpha;
	ptr_alpha = alpha ;

	for(i=0; i<26; i++){
		*(ptr_alpha) = 'A'+i ;
		ptr_alpha ++ ;
	}

	ptr_alpha = alpha ;
	for(i=0; i<26; i++){
		printf("%c ", *(ptr_alpha+i));
	}

	return 0;
}

