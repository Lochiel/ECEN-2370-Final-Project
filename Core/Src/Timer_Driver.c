/*
 * Timer_Driver.c
 *
 *  Created on: Oct 10, 2024
 *      Author: Lochi
 */

#include "Timer_Driver.h"

void Timer_Init(GPTIMR_RegDef_t* timer, GPTimer_Config_t config){

	Clk_Control(timer, ENABLE);

	timer->CR[0] &= ~(0x3 << CLK_DIV_OFFSET);
	timer->CR[0] |= (config.ClockDivision << CLK_DIV_OFFSET);

	timer->CR[0] &= ~(0x3 << CLK_CENTERED_MODE_OFFSET);
	timer->CR[0] |= (config.CenterAlignedMode << CLK_CENTERED_MODE_OFFSET);

	timer->CR[0] &= ~(0x1 << CLK_DIR_OFFSET);
	timer->CR[0] |= (config.CountDownModeEnabled << CLK_DIR_OFFSET);

	timer->CR[0] &= ~(0x1 << CLK_ARR_BUFFERED_OFFSET);
	timer->CR[0] |= (config.ARR_Buffer_Enabled << CLK_ARR_BUFFERED_OFFSET);

	timer->CR[0] &= ~(0x1 << CLK_ONEPULSE_OFFSET);
	timer->CR[0] |= (config.OnePulseModeEnabled << CLK_ONEPULSE_OFFSET);

	timer->CR[0] &= ~(0x1 << CLK_UPDATEDISABLE_OFFSET);
	timer->CR[0] |= (config.DisableUpdateEvent << CLK_UPDATEDISABLE_OFFSET);

	timer->PSC = config.Prescaler;
	timer->ARR = config.ARR;

	Timer_Interrupt_Enable(timer, config.InterruptUpdateEnabled);
}

void Clk_Control(GPTIMR_RegDef_t* timer, bool Enabled){
	if (Enabled == ENABLE){
		if (timer == TIM_7) { __HAL_RCC_TIM7_CLK_ENABLE(); }
	} else {
		if (timer == TIM_7) { __HAL_RCC_TIM7_CLK_DISABLE(); }
	}
}

void Timer_Start(GPTIMR_RegDef_t* timer){
	timer->CR[0] |= (0x1 << CLK_ENABLE_OFFSET);
}

void Timer_Stop(GPTIMR_RegDef_t* timer){
	timer->CR[0] &= ~(0x1 << CLK_ENABLE_OFFSET);
}

void Timer_Reset(GPTIMR_RegDef_t* timer){
	timer->CNT = 0;
}

uint32_t Timer_ARR_Value(GPTIMR_RegDef_t* timer){
	return timer->ARR;
}

uint32_t Timer_Value(GPTIMR_RegDef_t* timer){
	return timer->CNT;
}

void Timer_Set_ARR(GPTIMR_RegDef_t* timer, uint32_t new_ARR){
	timer->ARR = new_ARR;
}

void Timer_Interrupt_Enable(GPTIMR_RegDef_t* timer, uint8_t EnableDisable){
	timer->DIER &= ~(0x1 << CLK_INTERUPTUPDATE_OFFSET);
	if (EnableDisable == ENABLE) {
		timer->DIER |= (0x1 << CLK_INTERUPTUPDATE_OFFSET);
		if (timer == TIM_7) { IRQ_Enable(IRQ_TIM7); }
	} else {
		if (timer == TIM_7) { IRQ_Disable(IRQ_TIM7);}
	}
}

void Timer_Clear_SR(GPTIMR_RegDef_t* timer){
	timer->SR &= ~(0x1 << 0);
}

void Stopwatch_Increment(time_counter_t* stopwatch){
	stopwatch->seconds 	+= 1;
	stopwatch->minutes 	+= _check_Rollover(&stopwatch->seconds);
	stopwatch->hours	+= _check_Rollover(&stopwatch->minutes);
}

uint8_t _check_Rollover(uint8_t* time_unit){
	if (*time_unit >= SEC_PER_MINUTE){
		*time_unit = 0;
		return 1;
	} else {
		return 0;
	}
}

void Stopwatch_Reset(time_counter_t* stopwatch){
	stopwatch->seconds 	= 0;
	stopwatch->minutes 	= 0;
	stopwatch->hours	= 0;
}

void Stopwatch_To_String(time_counter_t* stopwatch, char* String){
	String[0] = '\0';
	char hours[30];
	char minutes[30];
	char seconds[30];

	sprintf(hours, "Hours: %d\n", stopwatch->hours);
	sprintf(minutes, " Minutes: %d\n", stopwatch->minutes);
	sprintf(seconds, " Seconds: %d\n", stopwatch->seconds);

	strcat(String, hours);
	strcat(String, minutes);
	strcat(String, seconds);
}

//void TimerToStopwatch(GPTIMR_RegDef_t* timer, time_counter_t* stopwatch){
//	uint8_t seconds;
//	uint32_t TimerCount = timer->CNT;
//	uint32_t TimerAAR	= timer->ARR;
//	if (TimerCount > 0){
//		seconds = (uint8_t)((TimerCount/TimerAAR)*SEC_PER_MINUTE);
//	} else {
//		seconds = 0;
//	}
//	stopwatch->seconds = seconds;
//}
