#include "fifo.h"
#include <stdlib.h>
#include <stdio.h>

#define buffer_length	5
FIFO_DATA_TYPE buff[buffer_length] ;

int main(){

	FIFO_buff_t UART_buff ;
	unsigned long i;
	FIFO_DATA_TYPE item ;
	FIFO_status_t st ;

	FIFO_init(&UART_buff, buff, buffer_length);
	printf("================ FIFO Push ================");
	printf("\n");
	printf("FIFO length = %d\n", UART_buff.length);
	for(i=0; i<5; i++){
		st = FIFO_enqueue(&UART_buff, i);
		printf("i = %d : FIFO_status = ", i);
		FIFO_get_strstatus(st);
		printf("\n");
	}
	printf("===========================================");
	printf("\n");
	for(i=0; i<5; i++){
		printf("%d\t", buff[i]);
	}
	printf("\n");
	printf("================ FIFO POP =================");
	printf("\n");
	for(i=0; i<7; i++){
		st = FIFO_dequeue(&UART_buff, &item);
		printf("item = %d : FIFO_status = ", item);
		FIFO_get_strstatus(st);
		printf("\n");
	}
	printf("===========================================");
	printf("\n");
	printf("============== FIFO Push POP ==============");
	printf("\n");
	printf("FIFO length = %d\n", UART_buff.length);
	for(i=0; i<4; i++){
		if(i%2 == 0){
			printf("FIFO Write : \n");
			st = FIFO_enqueue(&UART_buff, i);
			printf("i = %d : FIFO_status = ", i);
			FIFO_get_strstatus(st);
			printf("\n");
		}else{
			printf("FIFO Read : \n");
			st = FIFO_dequeue(&UART_buff, &item);
			printf("item = %d : FIFO_status = ", item);
			FIFO_get_strstatus(st);
			printf("\n");
		}

	}
	printf("===========================================");
	printf("\n");

	return 0;
}

