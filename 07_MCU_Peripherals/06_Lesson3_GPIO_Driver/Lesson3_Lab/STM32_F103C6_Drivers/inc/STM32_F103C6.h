/*
 * STM32_F103C6.h
 *
 *  Created on: Nov 7, 2022
 *      Author: Mohamed
 */

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
	volatile uint32_t EXTICR1 	;
	volatile uint32_t EXTICR2 	;
	volatile uint32_t EXTICR3 	;
	volatile uint32_t EXTICR4 	;
	volatile uint32_t RESERVED0 ;
	volatile uint32_t MAPR2 	;
}AFIO_Typedef_t;

//----------------------------------------
// Peripherals Register: EXTI
//----------------------------------------
typedef struct {
	volatile uint32_t IMR 	;
	volatile uint32_t EMR 	;
	volatile uint32_t RSTR 	;
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

/*********************************************************************/
/*********************************************************************/
					/* Clock Enable Macros */
#define RCC_GPIOA_CLK_EN()	(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()	(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()	(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()	(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()	(RCC->APB2ENR |= 1<<6)

#define RCC_AFIO_CLK_EN()	(RCC->APB2ENR |= 1<<0)

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
