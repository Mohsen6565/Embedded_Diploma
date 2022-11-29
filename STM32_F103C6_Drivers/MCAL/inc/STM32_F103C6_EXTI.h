#ifndef INC_STM32_F103C6_EXTI_H_
#define INC_STM32_F103C6_EXTI_H_

/*********************************************************************/
//							Includes
/*********************************************************************/
#include <stdint.h>
#include "STM32_F103C6.h"
#include "STM32_F103C6_GPIO.h"
/*********************************************************************/
/*********************************************************************/
// 						User Defined Types
/*********************************************************************/
typedef struct{
	GPIO_Typedef_t* 	GPIOx 		;
	uint8_t				pin_number 	;
	uint8_t 			line_number	;
	uint8_t 			IRQ_number	;
}EXTI_GPIO_Mapping_t;

typedef struct{
	EXTI_GPIO_Mapping_t EXTI_pin ;	// Specifies Mapping between GPIO pin to External Interrupt
									// This Value must be set according to @ref EXTI_define

	uint8_t trigger_mode		;	// Specifies Whether it is Rising, Falling, or both triggers
									// This Value must be set according to @ref EXTI_Trigger_define

	uint8_t IRQ_EN 				; 	// This value Enable or Disable EXTI IRQ
									// This Value must be set according to @ref EXTI_IRQ_define

	void(* IRQ_Callback)(void)	; 	// A pointer to the C function called from the Application layer

}EXTI_pin_config_t;
/*********************************************************************/
/*********************************************************************/
// 				Macros Configuration and References
/*********************************************************************/
#define EXTI_GPIO_Mapping(GPIOx)	((GPIOx == GPIOA)?(0):\
									 (GPIOx == GPIOB)?(1):\
									 (GPIOx == GPIOC)?(2):\
									 (GPIOx == GPIOD)?(3):0)

// @ref EXTI_define
//EXTI0
#define EXTI0_PINA0		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_0, EXIT0, EXTI0_IRQ})
#define EXTI0_PINB0		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_0, EXIT0, EXTI0_IRQ})
#define EXTI0_PINC0		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_0, EXIT0, EXTI0_IRQ})
#define EXTI0_PIND0		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_0, EXIT0, EXTI0_IRQ})
#define EXTI0_PINE0		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_0, EXIT0, EXTI0_IRQ})


//EXTI1
#define EXTI1_PINA1		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_1, EXIT1, EXTI1_IRQ})
#define EXTI1_PINB1		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_1, EXIT1, EXTI1_IRQ})
#define EXTI1_PINC1		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_1, EXIT1, EXTI1_IRQ})
#define EXTI1_PIND1		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_1, EXIT1, EXTI1_IRQ})
#define EXTI1_PINE1		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_1, EXIT1, EXTI1_IRQ})


//EXTI2
#define EXTI2_PINA2		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_2, EXIT2, EXTI2_IRQ})
#define EXTI2_PINB2		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_2, EXIT2, EXTI2_IRQ})
#define EXTI2_PINC2		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_2, EXIT2, EXTI2_IRQ})
#define EXTI2_PIND2		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_2, EXIT2, EXTI2_IRQ})
#define EXTI2_PINE2		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_2, EXIT2, EXTI2_IRQ})


//EXTI3
#define EXTI3_PINA3		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_3, EXIT3, EXTI3_IRQ})
#define EXTI3_PINB3		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_3, EXIT3, EXTI3_IRQ})
#define EXTI3_PINC3		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_3, EXIT3, EXTI3_IRQ})
#define EXTI3_PIND3		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_3, EXIT3, EXTI3_IRQ})
#define EXTI3_PINE3		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_3, EXIT3, EXTI3_IRQ})


//EXTI4
#define EXTI4_PINA4		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_4, EXIT4, EXTI4_IRQ})
#define EXTI4_PINB4		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_4, EXIT4, EXTI4_IRQ})
#define EXTI4_PINC4		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_4, EXIT4, EXTI4_IRQ})
#define EXTI4_PIND4		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_4, EXIT4, EXTI4_IRQ})
#define EXTI4_PINE4		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_4, EXIT4, EXTI4_IRQ})


//EXTI5
#define EXTI5_PINA5		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_5, EXIT5, EXTI5_IRQ})
#define EXTI5_PINB5		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_5, EXIT5, EXTI5_IRQ})
#define EXTI5_PINC5		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_5, EXIT5, EXTI5_IRQ})
#define EXTI5_PIND5		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_5, EXIT5, EXTI5_IRQ})
#define EXTI5_PINE5		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_5, EXIT5, EXTI5_IRQ})


//EXTI6
#define EXTI6_PINA6		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_6, EXIT6, EXTI6_IRQ})
#define EXTI6_PINB6		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_6, EXIT6, EXTI6_IRQ})
#define EXTI6_PINC6		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_6, EXIT6, EXTI6_IRQ})
#define EXTI6_PIND6		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_6, EXIT6, EXTI6_IRQ})
#define EXTI6_PINE6		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_6, EXIT6, EXTI6_IRQ})


//EXTI7
#define EXTI7_PINA7		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_7, EXIT7, EXTI7_IRQ})
#define EXTI7_PINB7		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_7, EXIT7, EXTI7_IRQ})
#define EXTI7_PINC7		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_7, EXIT7, EXTI7_IRQ})
#define EXTI7_PIND7		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_7, EXIT7, EXTI7_IRQ})
#define EXTI7_PINE7		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_7, EXIT7, EXTI7_IRQ})


//EXTI8
#define EXTI8_PINA8		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_8, EXIT8, EXTI8_IRQ})
#define EXTI8_PINB8		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_8, EXIT8, EXTI8_IRQ})
#define EXTI8_PINC8		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_8, EXIT8, EXTI8_IRQ})
#define EXTI8_PIND8		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_8, EXIT8, EXTI8_IRQ})
#define EXTI8_PINE8		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_8, EXIT8, EXTI8_IRQ})


//EXTI9
#define EXTI9_PINA9		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_9, EXIT9, EXTI9_IRQ})
#define EXTI9_PINB9		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_9, EXIT9, EXTI9_IRQ})
#define EXTI9_PINC9		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_9, EXIT9, EXTI9_IRQ})
#define EXTI9_PIND9		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_9, EXIT9, EXTI9_IRQ})
#define EXTI9_PINE9		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_9, EXIT9, EXTI9_IRQ})


//EXTI10
#define EXTI10_PINA10		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_10, EXIT10, EXTI10_IRQ})
#define EXTI10_PINB10		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_10, EXIT10, EXTI10_IRQ})
#define EXTI10_PINC10		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_10, EXIT10, EXTI10_IRQ})
#define EXTI10_PIND10		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_10, EXIT10, EXTI10_IRQ})
#define EXTI10_PINE10		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_10, EXIT10, EXTI10_IRQ})


//EXTI11
#define EXTI11_PINA11		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_11, EXIT11, EXTI11_IRQ})
#define EXTI11_PINB11		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_11, EXIT11, EXTI11_IRQ})
#define EXTI11_PINC11		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_11, EXIT11, EXTI11_IRQ})
#define EXTI11_PIND11		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_11, EXIT11, EXTI11_IRQ})
#define EXTI11_PINE11		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_11, EXIT11, EXTI11_IRQ})


//EXTI12
#define EXTI12_PINA12		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_12, EXIT12, EXTI12_IRQ})
#define EXTI12_PINB12		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_12, EXIT12, EXTI12_IRQ})
#define EXTI12_PINC12		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_12, EXIT12, EXTI12_IRQ})
#define EXTI12_PIND12		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_12, EXIT12, EXTI12_IRQ})
#define EXTI12_PINE12		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_12, EXIT12, EXTI12_IRQ})


//EXTI13
#define EXTI13_PINA13		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_13, EXIT13, EXTI13_IRQ})
#define EXTI13_PINB13		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_13, EXIT13, EXTI13_IRQ})
#define EXTI13_PINC13		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_13, EXIT13, EXTI13_IRQ})
#define EXTI13_PIND13		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_13, EXIT13, EXTI13_IRQ})
#define EXTI13_PINE13		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_13, EXIT13, EXTI13_IRQ})


//EXTI14
#define EXTI14_PINA14		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_14, EXIT14, EXTI14_IRQ})
#define EXTI14_PINB14		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_14, EXIT14, EXTI14_IRQ})
#define EXTI14_PINC14		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_14, EXIT14, EXTI14_IRQ})
#define EXTI14_PIND14		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_14, EXIT14, EXTI14_IRQ})
#define EXTI14_PINE14		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_14, EXIT14, EXTI14_IRQ})


//EXTI15
#define EXTI15_PINA15		((EXTI_GPIO_Mapping_t){GIOPA, GPIO_PIN_15, EXIT15, EXTI15_IRQ})
#define EXTI15_PINB15		((EXTI_GPIO_Mapping_t){GIOPB, GPIO_PIN_15, EXIT15, EXTI15_IRQ})
#define EXTI15_PINC15		((EXTI_GPIO_Mapping_t){GIOPC, GPIO_PIN_15, EXIT15, EXTI15_IRQ})
#define EXTI15_PIND15		((EXTI_GPIO_Mapping_t){GIOPD, GPIO_PIN_15, EXIT15, EXTI15_IRQ})
#define EXTI15_PINE15		((EXTI_GPIO_Mapping_t){GIOPE, GPIO_PIN_15, EXIT15, EXTI15_IRQ})


// @ref EXTI_Trigger_define
#define EXTI_Trigger_FALLING 				0
#define EXTI_Trigger_RISING 				1
#define EXTI_Trigger_FALLING_RISING 		2


// @ref EXTI_IRQ_define
#define EXTI_IRQ_DISABLE	0
#define EXTI_IRQ_ENABLE		1

// @ref EXTI
#define EXTI0		0
#define EXTI1		1
#define EXTI2		2
#define EXTI3		3
#define EXTI4		4
#define EXTI5		5
#define EXTI6		6
#define EXTI7		7
#define EXTI8		8
#define EXTI9		9
#define EXTI10		10
#define EXTI11		11
#define EXTI12		12
#define EXTI13		13
#define EXTI14		14
#define EXTI15		15

/*********************************************************************/
/*
 * ====================================================================
 *				APIs supported by STM32F103C6 MCAL GPIO Driver
 * ====================================================================
 */
void MCAL_EXTI_GPIO_Init(EXTI_pin_config_t* exti_pin_config);
void MCAL_EXTI_GPIO_Reset(void);
void MCAL_EXTI_GPIO_Update(EXTI_pin_config_t* exti_pin_config);



#endif /* INC_STM32_F103C6_EXTI_H_ */
