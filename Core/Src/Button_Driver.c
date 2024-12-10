/*
 * Button_Driver.c
 *
 *  Created on: Sep 24, 2024
 *      Author: Lochi
 */

#include "Button_Driver.h"


//#TODO finish converting this to HAL
void ButtonInit(){

	GPIO_InitTypeDef GPIOx_Init;

	GPIOx_Init.Pin = BUTTON_PIN;
	GPIOx_Init.Mode = GPIO_MODE_INPUT;
	GPIOx_Init.Pull = GPIO_NOPULL;
	GPIOx_Init.Speed = GPIO_SPEED_FREQ_LOW;

	GPIOG_CLK_ENABLE();
	HAL_GPIO_Init(BUTTON_PORT, &GPIOx_Init);
}


bool Button_Pressed(){
	GPIO_PinState button_status = HAL_GPIO_ReadPin(BUTTON_PORT, BUTTON_PIN);
	if (button_status == GPIO_PIN_SET) return true;
	return false;
}

void Button_EnableInterupt(){
	GPIO_InitTypeDef GPIOx_Init;

	GPIOx_Init.Pin = BUTTON_PIN;
	GPIOx_Init.Mode = GPIO_MODE_IT_RISING;
	GPIOx_Init.Speed = GPIO_SPEED_LOW;

	GPIOA_CLK_ENABLE();
	HAL_GPIO_Init(BUTTON_PORT, &GPIOx_Init);
	SysCfg_Init();
	Set_EXTI_Pin();
}

void Set_EXTI_Pin(){
	EXTI->IMR |= (0x1 << 0);
}

//Specific to EXTI0, User Button. Pin A1
void SysCfg_Init(){
	SYSCFG->EXTICR[0] |= (0 << 0);
}
