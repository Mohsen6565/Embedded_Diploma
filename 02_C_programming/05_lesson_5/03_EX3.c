#include <stdio.h>
#include <string.h>

void str_rev(char des[], char src[]);

int main(){
	char src[50], des[50]="";


	printf("Enter a Sentence: ");
	fflush(stdin); fflush(stdout);
	gets(src);

	str_rev(des, src);

	printf("%s\n", des);

	return 0;
}

void str_rev(char des[], char src[]){
	char str[50] ;
	int len;

	strcpy(str, src);
	len = strlen(str);
	/*
	*	printf("str = %s\n", str);
	*/
	if(len == 1){
		strcat(des, str);
		strcat(des, "\0");
	}else{
		strcat(des, str+len-1);
		/*
		 * printf("%s\n", des);
		 */
		str[len-1] = '\0';
		str_rev(des, str);
	}

}

