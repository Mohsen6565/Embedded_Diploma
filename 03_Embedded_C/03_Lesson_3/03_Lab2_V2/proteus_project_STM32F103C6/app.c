/* Registers Addresses*/
#define RCC_BASE		0x40021000
#define GPIOA_BASE		0x40010800
#define RCC_APB2ENR		*((volatile unsigned long *)(RCC_BASE + 0x18))
#define GPIOA_CRH		*((volatile unsigned long *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR		*((volatile unsigned long *)(GPIOA_BASE + 0x0C))
/* Pin Fields */
#define RCC_IOPAEN			2
#define GPIOA13				13
/* Some Macros */
#define SET_BIT(REG, BIT)	(REG = REG | (1<<BIT))
#define CLR_BIT(REG, BIT)	(REG = REG & ~(1<<BIT))

typedef union{
	volatile unsigned long all_fields;
	struct{
		volatile unsigned long reserved:13;
		volatile unsigned long P13:1 ;
	} Pin ;
} R_ODR_t ; 

volatile R_ODR_t* R_ODR = (volatile R_ODR_t *)(GPIOA_BASE + 0x0C) ;

/*Adding some Global Variables*/
unsigned long g_data[] = {1, 2, 3};
unsigned long const g_rodata[] = {4, 5, 6};
unsigned long g_bss[5];

int main(void){

	volatile int delay_count ;
	/* Enable Clock to Port A*/
	// SET_BIT(RCC_APB2ENR, RCC_IOPAEN);
	RCC_APB2ENR  |= (1<<2) ;

	/* Setting pin as Output */
	GPIOA_CRH &= 0xFF0FFFFF ;
	GPIOA_CRH |= 0x00200000 ;

	/* Toggle LED */
	while(1){
		/* LED ON*/
		R_ODR->Pin.P13 = 1 ;
		/* Some Delay */
		for(delay_count=0; delay_count< 5000; delay_count++);
		/* LED OFF */
		R_ODR->Pin.P13 = 0 ;
		/* Some Delay */
		for(delay_count=0; delay_count< 5000; delay_count++);
	}

	return 0;
}