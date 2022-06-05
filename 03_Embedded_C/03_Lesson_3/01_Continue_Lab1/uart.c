#include "uart.h"

/* Define UART Register */
#define UART_DR0	*((volatile unsigned int* const)((unsigned int*)0x101f1000))

void UART_send_string(unsigned char *Ptr_tx_string){
	/* Loop until the end of the string */
	while(*Ptr_tx_string != '\0'){
		/* Trasmit a Character */
		UART_DR0 = (unsigned int)*Ptr_tx_string ;
		/* Move pointer to the next character */
		Ptr_tx_string ++ ;
	}
}