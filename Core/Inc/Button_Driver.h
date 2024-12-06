/*
 * Button_Driver.h
 *
 *  Created on: Sep 24, 2024
 *      Author: Lochi
 */

#ifndef BUTTON_DRIVER_H_
#define BUTTON_DRIVER_H_

#include "stm32.h"
#include "stm32f4xx_hal.h"
#include "InterruptControl.h"


#define BUTTON_PORT GPIOA
#define BUTTON_PIN GPIO_PIN_0
#define BUTTON_PRESSED 1
#define BUTTON_NOT_PRESSED !BUTTON_PRESSED

void ButtonInit();
void Button_ClockEnable();
void Button_ClockDisable();
bool Button_Pressed();

void Button_EnableInterupt();


#endif /* BUTTON_DRIVER_H_ */
