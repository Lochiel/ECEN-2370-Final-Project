/*
 * InterruptControl.c
 *
 *  Created on: Sep 28, 2024
 *      Author: Lochi
 */

#include "InterruptControl.h"

void IRQ_Enable(IRQn_Type irq){
	HAL_NVIC_EnableIRQ(irq);
}

void IRQ_Disable(IRQn_Type irq){
	HAL_NVIC_DisableIRQ(irq);
}

void IRQ_Clear(IRQn_Type irq){
	HAL_NVIC_ClearPendingIRQ(irq);
}

void EXTI_ClearPending(IRQn_Type irq){
	EXTI_HandleTypeDef exti;
	if 		(irq == EXTI0_IRQn) { exti.Line = EXTI_LINE_0;}
	else if	(irq == EXTI1_IRQn) { exti.Line = EXTI_LINE_1;}
	HAL_EXTI_ClearPending(&exti, EXTI_TRIGGER_RISING_FALLING);
}

void NVICEnableDisable(IRQn_Type irq, bool enabled){
	if (enabled == ENABLE){
		IRQ_Enable(irq);
	} else {
		IRQ_Disable(irq);
	}
}
