/*
 * Assignment1_Code.c
 *
 * Created: 10/23/2022 10:59:34 PM
 *  Author: Mohamed
 */ 

#include "ATmega32.h"
//#include <avr/io.h>
#define F_CPU 1000000UL

void Setup(void){
	DDRD |= (1<<4) | (1<<5) | (1<<6) | (1<<7) ;
}
void my_delay(int x){
	int i, j ;
	for(i=0; i<x; i++){
		for(j=0; j<100000; j++);
	}
}

int main(void){
	Setup();
	int i, x ;
	x = 100000 ;
 
	
    while(1){
		for(i=0; i<4; i++){
			switch(i){
				case 0:
					PORTD |= (1<<4) ;
					PORTD &= ~(1<<5);
					PORTD &= ~(1<<6);
					PORTD &= ~(1<<7);
					my_delay(x);
				break;
				case 1:
					PORTD &= ~(1<<4) ;
					PORTD |= (1<<5);
					PORTD &= ~(1<<6);
					PORTD &= ~(1<<7);
					my_delay(x);
				break;
				case 2:
					PORTD &= ~(1<<4);
					PORTD &= ~(1<<5);
					PORTD |= (1<<6);
					PORTD &= ~(1<<7);
					my_delay(x);
				break;
				case 3:
					PORTD &= ~(1<<4);
					PORTD &= ~(1<<5);
					PORTD &= ~(1<<6);
					PORTD |= (1<<7);
					my_delay(x);
				break;
			}
			
		}
	
    }
}

