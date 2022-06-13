#include <stdlib.h>
#include "lifo.h"
#include <stdio.h>

unsigned char buff[5] ;
LIFO_buff_t lifo_buff ;

int main(){
	unsigned long i ;
	LIFO_status_t st ;
	unsigned char item ;

	lifo_buff.base = buff ;
	lifo_buff.head = buff ;
	lifo_buff.length = 5 ;
	lifo_buff.count = 0 ;
	printf("================ LIFO Push ================");
	printf("\n");
	printf("LIFO length = %d\n", lifo_buff.length);
	for(i=2; i<10; i++){
		st = LIFO_push(&lifo_buff, i);
		printf("i = %d : LIFO_status = ", i);
		LIFO_get_strstatus(st);
		printf("\n");
	}
	printf("===========================================");
	printf("\n");
	for(i=0; i<5; i++){
			printf("%d\t", buff[i]);
	}
	printf("\n");
	printf("================ LIFO POP =================");
	printf("\n");
	for(i=0; i<7; i++){
		st = LIFO_pop(&lifo_buff, &item);
		printf("item = %d : LIFO_status = ", item);
		LIFO_get_strstatus(st);
		printf("\n");
	}
	printf("===========================================");
	printf("\n");

	return 0;
}

