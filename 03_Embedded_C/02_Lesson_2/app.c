#include "uart.h"

unsigned char string_buff[100] = "Learn-in-Depth:<Mohamed>";

int main(void){

	UART_send_string(string_buff);

	return 0;
}