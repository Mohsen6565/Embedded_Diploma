/*
 * ====================================================================
 *								Includes
 * ====================================================================
 */
#include <stdint.h>
#include <stdlib.h>
#include "STM32_F103C6.h"
#include "STM32_F103C6_GPIO.h"
#include "STM32_F103C6_EXTI.h"


/*
 * ====================================================================
 *						Generic Variables
 * ====================================================================
 */
void(* GP_IRQ_Callback[16])(void) ;

/*
 * ====================================================================
 *						IRQ Handlers
 * ====================================================================
 */
void EXTI0_IRQHandler(void){
// 	Disable Pending Interrupt
	SET_BIT(EXTI->PR, 0);
// 	Call The Callback Function
	GP_IRQ_Callback[0]();

}

void EXTI1_IRQHandler(void){
// 	Disable Pending Interrupt
	SET_BIT(EXTI->PR, 1);
// 	Call The Callback Function
	GP_IRQ_Callback[1]();
}

void EXTI2_IRQHandler(void){
// 	Disable Pending Interrupt
	SET_BIT(EXTI->PR, 2);
// 	Call The Callback Function
	GP_IRQ_Callback[2]();
}

void EXTI3_IRQHandler(void){
// 	Disable Pending Interrupt
	SET_BIT(EXTI->PR, 3);
// 	Call The Callback Function
	GP_IRQ_Callback[3]();
}

void EXTI4_IRQHandler(void){
// 	Disable Pending Interrupt
	SET_BIT(EXTI->PR, 4);
// 	Call The Callback Function
	GP_IRQ_Callback[4]();
}

void EXTI9_5_IRQHandler(void){
	if(READ_BIT(EXTI->PR, 5)) { SET_BIT(EXTI->PR, 5) ; 	GP_IRQ_Callback[5]() ; }
	if(READ_BIT(EXTI->PR, 6)) { SET_BIT(EXTI->PR, 6) ; 	GP_IRQ_Callback[6]() ; }
	if(READ_BIT(EXTI->PR, 7)) { SET_BIT(EXTI->PR, 7) ; 	GP_IRQ_Callback[7]() ; }
	if(READ_BIT(EXTI->PR, 8)) { SET_BIT(EXTI->PR, 8) ; 	GP_IRQ_Callback[8]() ; }
	if(READ_BIT(EXTI->PR, 9)) { SET_BIT(EXTI->PR, 9) ; 	GP_IRQ_Callback[9]() ; }
}

void EXTI15_10_IRQHandler(void){
	if(READ_BIT(EXTI->PR, 10)) { SET_BIT(EXTI->PR, 10) ; 	GP_IRQ_Callback[10]() ; }
	if(READ_BIT(EXTI->PR, 11)) { SET_BIT(EXTI->PR, 11) ; 	GP_IRQ_Callback[11]() ; }
	if(READ_BIT(EXTI->PR, 12)) { SET_BIT(EXTI->PR, 12) ; 	GP_IRQ_Callback[12]() ; }
	if(READ_BIT(EXTI->PR, 13)) { SET_BIT(EXTI->PR, 13) ; 	GP_IRQ_Callback[13]() ; }
	if(READ_BIT(EXTI->PR, 14)) { SET_BIT(EXTI->PR, 14) ; 	GP_IRQ_Callback[14]() ; }
	if(READ_BIT(EXTI->PR, 15)) { SET_BIT(EXTI->PR, 15) ; 	GP_IRQ_Callback[15]() ; }
}
/*
 * ====================================================================
 *						Generic Functions
 * ====================================================================
 */
void NVIC_EXTI_IRQ_en(uint8_t EXTI_num){
	switch(EXTI_num){
		case 0:
			NVIC_IRQ6_EXTI0_ENABLE() ;
			break ;
		case 1:
			NVIC_IRQ6_EXTI1_ENABLE() ;
			break ;
		case 2:
			NVIC_IRQ6_EXTI2_ENABLE() ;
			break ;
		case 3:
			NVIC_IRQ6_EXTI3_ENABLE() ;
			break ;
		case 4:
			NVIC_IRQ6_EXTI4_ENABLE() ;
			break ;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI5_9_ENABLE() ;
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ23_EXTI10_15_ENABLE() ;
			break;
	}
}

void NVIC_EXTI_IRQ_dis(uint8_t EXTI_num){
	switch(EXTI_num){
		case 0:
			NVIC_IRQ6_EXTI0_DISABLE() ;
			break ;
		case 1:
			NVIC_IRQ6_EXTI1_DISABLE() ;
			break ;
		case 2:
			NVIC_IRQ6_EXTI2_DISABLE() ;
			break ;
		case 3:
			NVIC_IRQ6_EXTI3_DISABLE() ;
			break ;
		case 4:
			NVIC_IRQ6_EXTI4_DISABLE() ;
			break ;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			NVIC_IRQ23_EXTI5_9_DISABLE() ;
			break;
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:
		case 15:
			NVIC_IRQ23_EXTI10_15_DISABLE() ;
			break;
	}
}

void update_EXTI(EXTI_pin_config_t* EXTI_pin_config){
//=======================================================
// 	[1] Configure the pin as an AFIO ---> Floating Input
	GPIO_pin_config_t GPIO_pin_config ;
	GPIO_pin_config.GPIO_pin_number = EXTI_pin_config->EXTI_pin.pin_number ;
	GPIO_pin_config.GPIO_pin_mode = GPIO_MODE_INPUT_FLOATING ;
	MCAL_GPIO_Init(EXTI_pin_config->EXTI_pin.GPIOx, &GPIO_pin_config);

//=======================================================
// [2] Configure Routing between GPIO Pin and EXTI Line
	uint8_t AFIO_EXTICR_indx 		= EXTI_pin_config->EXTI_pin.line_number / 4 ;
	uint8_t AFIO_EXRCR_offset 		= (EXTI_pin_config->EXTI_pin.line_number % 4) * 4 ;
	AFIO->EXTICR[AFIO_EXTICR_indx] 	&= ~((0xF) << AFIO_EXRCR_offset);
	AFIO->EXTICR[AFIO_EXTICR_indx] 	|= ((EXTI_GPIO_Mapping(EXTI_pin_config->EXTI_pin.GPIOx) & 0xF) << AFIO_EXRCR_offset) ;

//=======================================================
// [3] Configure Routing between GPIO Pin and EXTI Line
	CLEAR_BIT(EXTI->FTSR, EXTI_pin_config->EXTI_pin.line_number);
	CLEAR_BIT(EXTI->RTSR, EXTI_pin_config->EXTI_pin.line_number);

	if(EXTI_pin_config->trigger_mode == EXTI_Trigger_FALLING){
		SET_BIT(EXTI->FTSR, EXTI_pin_config->EXTI_pin.line_number);

	}else if(EXTI_pin_config->trigger_mode == EXTI_Trigger_RISING){
		SET_BIT(EXTI->RTSR, EXTI_pin_config->EXTI_pin.line_number);

	}else if(EXTI_pin_config->trigger_mode == EXTI_Trigger_FALLING_RISING){
		SET_BIT(EXTI->FTSR, EXTI_pin_config->EXTI_pin.line_number);
		SET_BIT(EXTI->RTSR, EXTI_pin_config->EXTI_pin.line_number);
	}
//=======================================================
// [4] Update IRQ Handling Callback
	GP_IRQ_Callback[EXTI_pin_config->EXTI_pin.line_number] = EXTI_pin_config->IRQ_Callback;

//=======================================================
// [5] Enable/Disable IRQ EXIT & NVIC
	if(EXTI_pin_config->IRQ_EN == EXTI_IRQ_ENABLE){
		// Set Interrupt Mask to 1
		SET_BIT(EXTI->IMR, EXTI_pin_config->EXTI_pin.line_number);
		// Set NVIC Mask to 1
		NVIC_EXTI_IRQ_en(EXTI_pin_config->EXTI_pin.line_number);
	}else{
		// Set Interrupt Mask to 0
		CLEAR_BIT(EXTI->IMR, EXTI_pin_config->EXTI_pin.line_number);
		// Set NVIC Mask to 0
		NVIC_EXTI_IRQ_dis(EXTI_pin_config->EXTI_pin.line_number);

	}
}


/*
 * ====================================================================
 *				APIs supported by STM32F103C6 MCAL GPIO Driver
 * ====================================================================
 */

/* ================================================================
 * @Fn: 		- MCAL_EXTI_GPIO_Init
 * @brief:		- Initializes External Interrupt Pin
 * @Inputs:		- [1] Name: EXTI_pin_config
 * 					  Type: EXTI_pin_config_t*
 * @Outputs:	- None
 * @retval:		- None
 * @Note:
 *
 */
void MCAL_EXTI_GPIO_Init(EXTI_pin_config_t* EXTI_pin_config){
	update_EXTI(EXTI_pin_config);
}

/* ================================================================
 * @Fn: 		- MCAL_EXTI_GPIO_Reset
 * @brief:		- Reset External Interrupt Module and Disables all External interrupts
 * @Inputs:		- None
 * @Outputs:	- None
 * @retval:		- None
 * @Note:
 *
 */
void MCAL_EXTI_GPIO_Reset(void){
	EXTI->IMR 	= 0x00000000 ;
	EXTI->EMR 	= 0x00000000 ;
	EXTI->RSTR 	= 0x00000000 ;
	EXTI->FTSR	= 0x00000000 ;
	EXTI->SWIER	= 0x00000000 ;
	EXTI->PR	= 0xFFFFFFFF ;
	// Disable NVIC IRQ Enable
	NVIC_IRQ6_EXTI0_DISABLE()  		;
	NVIC_IRQ7_EXTI1_DISABLE()  		;
	NVIC_IRQ8_EXTI2_DISABLE()  		;
	NVIC_IRQ9_EXTI3_DISABLE()  		;
	NVIC_IRQ10_EXTI4_DISABLE() 		;
	NVIC_IRQ23_EXTI5_9_DISABLE()	;
	NVIC_IRQ23_EXTI10_15_DISABLE()	;
}

/* ================================================================
 * @Fn: 		- MCAL_EXTI_GPIO_Update
 * @brief:		- Updates the External Interrupt configuration for some pin
 * @Inputs:		- [1] Name: EXTI_pin_config
 * 					  Type: EXTI_pin_config_t*		-
 * @Outputs:	- None
 * @retval:		- None
 * @Note:
 *
 */
void MCAL_EXTI_GPIO_Update(EXTI_pin_config_t* EXTI_pin_config){
	update_EXTI(EXTI_pin_config);
}
