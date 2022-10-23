/* Registers Addresses */
// Clock Register
#define RCC_BASE		0x40021000
#define RCC_APB2ENR		*((volatile unsigned int *)(RCC_BASE + 0x18))

// GPIO
#define GPIOA_BASE		0x40021000
#define GPIOA_CRH		*((volatile unsigned int *)(GPIOA_BASE + 0x04))
#define GPIOA_CRL		*((volatile unsigned int *)(GPIOA_BASE + 0x00))
#define GPIOA_ODR		*((volatile unsigned int *)(GPIOA_BASE + 0x0C))
#define GPIOA_IDR		*((volatile unsigned int *)(GPIOA_BASE + 0x08))

#define GPIOB_BASE		0x40021000
#define GPIOB_CRH		*((volatile unsigned int *)(GPIOB_BASE + 0x04))
#define GPIOB_CRL		*((volatile unsigned int *)(GPIOB_BASE + 0x00))
#define GPIOB_ODR		*((volatile unsigned int *)(GPIOB_BASE + 0x0C))
#define GPIOB_IDR		*((volatile unsigned int *)(GPIOB_BASE + 0x08))

void clock_init(void) {
	// Clock Enable for PortA
	RCC_APB2ENR |= 1 << 2;
	// Clock Enable for PortB
	RCC_APB2ENR |= 1 << 3;
}
void GPIO_init(void) {
//	PA1 and PA13 are configured as floating input pins
	// PA1
	GPIOA_CRL &= ~(1 << 0);
	GPIOA_CRL &= ~(1 << 1);
	GPIOA_CRL |= (1 << 2);
	GPIOA_CRL &= ~(1 << 3);

	// PA13
	GPIOA_CRH &= ~(1 << 20);
	GPIOA_CRH &= ~(1 << 21);
	GPIOA_CRH |= (1 << 22);
	GPIOA_CRH &= ~(1 << 23);

//	PB1 and PB13 are configured as output pins
	// PB1
	GPIOB_CRL |=  (1 << 0);
	GPIOB_CRL &= ~(1 << 1);
	GPIOB_CRL &= ~(1 << 2);
	GPIOB_CRL &= ~(1 << 3);

	// PB13
	GPIOB_CRH |=  (1 << 20);
	GPIOB_CRH &= ~(1 << 21);
	GPIOB_CRH &= ~(1 << 22);
	GPIOB_CRH &= ~(1 << 23);

}
void my_delay(int x){
	for(int i=0; i<x; i++){
		for(int j=0; j<256; j++);
	}
}

int main() {
	clock_init();
	GPIO_init();

	while (1) {
		if( ((GPIOA_IDR & (1<<1))>>1) == 0 ){
			GPIOB_ODR ^= 1<<1 ;
			while(((GPIOA_IDR & (1<<1))>>1) == 0 );
		}
		if( ((GPIOA_IDR & (1<<13))>>13) == 1 ){
			GPIOB_ODR ^= 1<<13 ;
			my_delay(1000);
		}
	}
}
