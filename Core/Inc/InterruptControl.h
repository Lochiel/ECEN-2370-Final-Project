/*
 * InterruptControl.h
 *
 *  Created on: Sep 28, 2024
 *      Author: Lochi
 */


#ifndef INTERRUPTCONTROL_H_
#define INTERRUPTCONTROL_H_

#include "stm32.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>


#define IRQ_EXTI0			EXTI0_IRQn
#define IRQ_EXTI1			EXTI1_IRQn
#define IRQ_EXTI2			EXTI2_IRQn
#define IRQ_EXTI3			EXTI3_IRQn
#define IRQ_EXTI4			EXTI4_IRQn

#define BTN_EXTI 			EXTI0

#define MAX_VALID_IRQ 			32
#define MAX_VALID_PENDING_IRQ	22

//#define INTERRUPT_MODE_NONE					EXTI_TRIGGER_NONE
//#define INTERRUPT_MODE_RISING				EXTI_TRIGGER_RISING
//#define INTERRUPT_MODE_FALLING				EXTI_TRIGGER_FALLING
//#define INTERRUPT_MODE_BOTH					EXTI_TRIGGER_RISING_FALLING


#define EXTI_TRIGGER_NONE                   0x00000000u
#define EXTI_TRIGGER_RISING                 0x00000001u
#define EXTI_TRIGGER_FALLING                0x00000002u
#define EXTI_TRIGGER_RISING_FALLING         (EXTI_TRIGGER_RISING | EXTI_TRIGGER_FALLING)

#define PORT_GPIOA				0
#define PORT_GPIOB				1
#define PORT_GPIOC				2
#define PORT_GPIOD				3
#define PORT_GPIOE				4
#define PORT_GPIOF				5
#define PORT_GPIOG				6
#define PORT_GPIOH				7
#define PORT_GPIOI				8
#define PORT_GPIOJ				9
#define PORT_GPIOK				10


void IRQ_Enable(IRQn_Type irq);
void IRQ_Disable(IRQn_Type irq);
void IRQ_Clear(IRQn_Type irq);
void IRQ_Set(IRQn_Type irq);
void EXTI_ClearPending(IRQn_Type irq);
void NVICEnableDisable(IRQn_Type, bool);

void Reset_Pending_Interrupt(IRQn_Type pin);

#endif /* INTERRUPTCONTROL_H_ */
