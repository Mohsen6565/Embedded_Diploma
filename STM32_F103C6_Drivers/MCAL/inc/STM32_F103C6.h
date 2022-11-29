#ifndef STM32_F103C6_H_
#define STM32_F103C6_H_
/*********************************************************************/
					/* Includes */
#include <stdint.h>

/*********************************************************************/
/*********************************************************************/
/* Memories Base Addresses */
#define FLASH_MEMORY_BASE						0x08000000UL
#define SRAM_MEMORY_BASE						0x20000000UL
#define SYSTEM_MEMORY_BASE						0x1FFFF000UL
#define PERIPHERALS_BASE						0x40000000UL
#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE		0xE0000000UL

/*********************************************************************/
/*********************************************************************/
					/* Peripherals Base Addresses */
//----------------------------------------
// Base Addresses for AHB Peripherals
//----------------------------------------
#define RCC_BASE 							0x40021000UL

//----------------------------------------
// Base Addresses for APB2 Peripherals
//----------------------------------------
// GPIO
#define GPIOA_BASE							0x40010800UL
#define GPIOB_BASE							0x40010C00UL
#define GPIOC_BASE							0x40011000UL
#define GPIOD_BASE							0x40011400UL
#define GPIOE_BASE							0x40011800UL

// AFIO
#define AFIO_BASE							0x40010000UL

// EXTI
#define EXTI_BASE							0x40010400UL

// NVIC
#define NVIC_BASE							0xE000E100UL

/*********************************************************************/
/*********************************************************************/
					/* Peripheral Registers */
//----------------------------------------
// Peripherals Register: RCC
//----------------------------------------
typedef struct {
	volatile uint32_t CR 		;
	volatile uint32_t CFGR 		;
	volatile uint32_t CIR 		;
	volatile uint32_t APB2RSTR 	;
	volatile uint32_t APB1RSTR 	;
	volatile uint32_t AHBENR 	;
	volatile uint32_t APB2ENR 	;
	volatile uint32_t APB1ENR 	;
	volatile uint32_t BDCR 		;
	volatile uint32_t CSR 		;
}RCC_Typedef_t;

//----------------------------------------
// Peripherals Register: GPIO
//----------------------------------------
typedef struct {
	volatile uint32_t CRL 	;
	volatile uint32_t CRH 	;
	volatile uint32_t IDR 	;
	volatile uint32_t ODR 	;
	volatile uint32_t BSRR 	;
	volatile uint32_t BRR 	;
	volatile uint32_t LCKR 	;
}GPIO_Typedef_t;

//----------------------------------------
// Peripherals Register: AFIO
//----------------------------------------
typedef struct {
	volatile uint32_t EVCR 		;
	volatile uint32_t MAPR		;
//	volatile uint32_t EXTICR1 	;
//	volatile uint32_t EXTICR2 	;
//	volatile uint32_t EXTICR3 	;
//	volatile uint32_t EXTICR4 	;
	volatile uint32_t EXTICR[4] ;
	volatile uint32_t RESERVED0 ;
	volatile uint32_t MAPR2 	;
}AFIO_Typedef_t;

//----------------------------------------
// Peripherals Register: EXTI
//----------------------------------------
typedef struct {
	volatile uint32_t IMR 	;
	volatile uint32_t EMR 	;
	volatile uint32_t RTSR 	;
	volatile uint32_t FTSR 	;
	volatile uint32_t SWIER ;
	volatile uint32_t PR 	;
}EXTI_Typedef_t;

/*********************************************************************/
/*********************************************************************/
					/* Peripherals Instants */
//----------------------------------------
// Peripherals Instants: RCC
//----------------------------------------
#define RCC		((RCC_Typedef_t*)(RCC_BASE))

//----------------------------------------
// Peripherals Instants: GPIO
//----------------------------------------
#define GPIOA		((GPIO_Typedef_t*)(GPIOA_BASE))
#define GPIOB		((GPIO_Typedef_t*)(GPIOB_BASE))
#define GPIOC		((GPIO_Typedef_t*)(GPIOC_BASE))
#define GPIOD		((GPIO_Typedef_t*)(GPIOD_BASE))
#define GPIOE		((GPIO_Typedef_t*)(GPIOE_BASE))

//----------------------------------------
// Peripherals Instants: AFIO
//----------------------------------------
#define AFIO		((AFIO_Typedef_t*)(AFIO_BASE))

//----------------------------------------
// Peripherals Instants: EXTI
//----------------------------------------
#define EXTI		((EXTI_Typedef_t*)(EXTI_BASE))

//----------------------------------------
// Peripherals Instants: NVIC Register Map
//----------------------------------------
#define NVIC_ISER0		(*(volatile uint32_t *)(NVIC_BASE + 0x000))
#define NVIC_ISER1		(*(volatile uint32_t *)(NVIC_BASE + 0x004))
#define NVIC_ISER2		(*(volatile uint32_t *)(NVIC_BASE + 0x008))
#define NVIC_ICER0		(*(volatile uint32_t *)(NVIC_BASE + 0x080))
#define NVIC_ICER1		(*(volatile uint32_t *)(NVIC_BASE + 0x084))
#define NVIC_ICER2		(*(volatile uint32_t *)(NVIC_BASE + 0x088))

/*********************************************************************/
/*********************************************************************/

/*-*-*-*-*- Clock Enable Macros *-*-*-*-*-*/
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1<<0)


/*-*-*-*-*- NVIC Interrupt Enable Macros *-*-*-*-*-*/
#define NVIC_IRQ6_EXTI0_ENABLE()			(NVIC_ISER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_ENABLE()			(NVIC_ISER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_ENABLE()			(NVIC_ISER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_ENABLE()			(NVIC_ISER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_ENABLE()			(NVIC_ISER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_ENABLE()			(NVIC_ISER0 |= (1<<23))
#define NVIC_IRQ23_EXTI10_15_ENABLE()		(NVIC_ISER1 |= (1<<8))

#define NVIC_IRQ6_EXTI0_DISABLE()			(NVIC_ICER0 |= (1<<6))
#define NVIC_IRQ7_EXTI1_DISABLE()			(NVIC_ICER0 |= (1<<7))
#define NVIC_IRQ8_EXTI2_DISABLE()			(NVIC_ICER0 |= (1<<8))
#define NVIC_IRQ9_EXTI3_DISABLE()			(NVIC_ICER0 |= (1<<9))
#define NVIC_IRQ10_EXTI4_DISABLE()			(NVIC_ICER0 |= (1<<10))
#define NVIC_IRQ23_EXTI5_9_DISABLE()		(NVIC_ICER0 |= (1<<23))
#define NVIC_IRQ23_EXTI10_15_DISABLE()		(NVIC_ICER1 |= (1<<8))


/*-*-*-*-*- IVT *-*-*-*-*-*/
// EXTI
#define EXTI0_IRQ	6
#define EXTI1_IRQ	7
#define EXTI2_IRQ	8
#define EXTI3_IRQ	9
#define EXTI4_IRQ	10
#define EXTI5_IRQ	23
#define EXTI6_IRQ	23
#define EXTI7_IRQ	23
#define EXTI8_IRQ	23
#define EXTI9_IRQ	23
#define EXTI10_IRQ	40
#define EXTI11_IRQ	40
#define EXTI12_IRQ	40
#define EXTI13_IRQ	40
#define EXTI14_IRQ	40
#define EXTI15_IRQ	40

/*********************************************************************/
/*********************************************************************/
					/* Generic Macros */
#define SET_BIT(REG, BIT)		(REG |= 1<<BIT)
#define CLEAR_BIT(REG, BIT)		(REG &= ~(1<<BIT))
#define READ_BIT(REG, BIT)		((REG & (1<<BIT))>>BIT)
#define TOGGLE_BIT(REG, BIT)	(REG ^= 1<<BIT)
#define SHIFT_LEFT(INDEX)		(1<<INDEX)
/*********************************************************************/



#endif /* STM32_F103C6_H_ */
