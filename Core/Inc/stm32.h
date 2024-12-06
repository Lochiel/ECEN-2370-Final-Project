/*
 * stm32.h
 *
 *  Created on: Nov 6, 2024
 *      Author: Lochi
 */

#ifndef INC_STM32_H_
#define INC_STM32_H_

#include "stm32f4xx.h"

#define pass 		(void)0
#define unused(var)	(void)var

#define ArraySize(x) 	(sizeof(x)/sizeof((x)[0]) )

#define HAL_DELAY_COEFFICENT	100

//////////////////////////////////
// Defined Keywords
//////////////////////////////////
#define ACTIVE		1
#define NON_ACTIVE	0
#define SET			1
#define RESET		0
#define ENABLE		SET
#define ENABLED		SET
#define DISABLE		RESET
#define DISABLED	RESET

//////////////////////////////////
// Macro Functions
//////////////////////////////////
// Clock Controls

#define GPIO_CLK_ENABLE(bit) 	(RCC->AHB1ENR |= (1 << bit))
#define GPIO_CLK_DISABLE(bit) 	(RCC->AHB1ENR &= ~(1 << bit))

#define GPIOA_CLK_ENABLE()		(GPIO_CLK_ENABLE(0))
#define GPIOA_CLK_DISABLE() 	(GPIO_CLK_DISABLE(0))

#define GPIOG_CLK_ENABLE() 		(GPIO_CLK_ENABLE(6))
#define GPIOG_CLK_DISABLE() 	(GPIO_CLK_DISABLE(6))

#define SYSCFG_CLK_ENABLE()		(RCC->APB2ENR |= (1<<14))
#define	SYSCFG_CLK_DISABLE()	(RCC->APB2ENR &= ~(1<<14))


#define TIM_CLK_ENABLE(bit)			(RCC->APB1ENR |= (1<<bit))
#define TIM_CLK_DISABLE(bit)		(RCC->APB1ENR &= ~(1<<bit))

#define TIM2_CLK_ENABLE()			(TIM_CLK_ENABLE(0))
#define TIM5_CLK_ENABLE()			(TIM_CLK_ENABLE(3))

#define TIM2_CLK_DISABLE()			(TIM_CLK_DISABLE(0))
#define TIM5_CLK_DISABLE()			(TIM_CLK_DISABLE(3))

#endif /* INC_STM32_H_ */
