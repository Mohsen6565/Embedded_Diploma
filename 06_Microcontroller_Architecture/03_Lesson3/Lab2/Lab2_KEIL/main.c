#include <stdint.h>
#include <stdlib.h>

#define RCC_BASE		0x40021000
#define RCC_CR			*(volatile uint32_t *)(RCC_BASE + 0x00)
#define RCC_CFGR		*(volatile uint32_t *)(RCC_BASE + 0x04)

int main(void)
{
	// Setting system Clock as HSI
	RCC_CFGR &= (0xFFFFFFFC);
	// Setting AHB Scaler "System Clock Prescaler" SYSCLK
	RCC_CFGR &= (0xFFFFFF0F);
	// Setting APB1 Scaler "PCLK1" to divide by 2
	RCC_CFGR |= (0b100)<<8 ;
	// Setting APB2 Scaler "PCLK2" to divide by 4
	RCC_CFGR |= (0b101)<<11 ;
	// Enable High Speed Internal Clock
	RCC_CR |= 1<<0 ;

	while(1){

	}
}
