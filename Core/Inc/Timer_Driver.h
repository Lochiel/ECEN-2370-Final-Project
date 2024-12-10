/*
 * Timer_Driver.h
 *
 *  Created on: Oct 10, 2024
 *      Author: Lochi
 */

#ifndef TIMER_DRIVER_H_
#define TIMER_DRIVER_H_

//#include "STM32F429i.h"

#include "stm32f4xx_hal.h"
#include "ili9341.h"
#include "InterruptControl.h"
#include "stm32.h"
#include <strings.h>

typedef struct{
	uint32_t ARR;					// Default value = 0
	uint8_t MasterMode;
	uint8_t ClockDivision;			// Default value = CLK_DIV_1
	uint16_t Prescaler;				// Default value = 0
	uint8_t CenterAlignedMode;		// Default value = 0
	bool ARR_Buffer_Enabled;		// Default - DISABLED
	bool CountDownModeEnabled;		// Default - DISABLED
	bool InterruptUpdateEnabled;	// Default - DISABLED
	bool DisableUpdateEvent;		// Default - DISABLED
	bool OnePulseModeEnabled;		// Default - DISABLED
}GPTimer_Config_t;

typedef struct{
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
}time_counter_t;

// Clk Counts per second = Counter Clock Freq / Clock Division / Prescaler

void Timer_Init(GPTIMR_RegDef_t* timer, GPTimer_Config_t config);
void Clk_Control(GPTIMR_RegDef_t* timer, bool Enabled);
void Timer_Start(GPTIMR_RegDef_t* timer);
void Timer_Stop(GPTIMR_RegDef_t* timer);
void Timer_Reset(GPTIMR_RegDef_t* timer);

uint32_t Timer_Value(GPTIMR_RegDef_t* timer);

void Timer_Interrupt_Enable(GPTIMR_RegDef_t*, uint8_t EnableDisable);
uint32_t Timer_ARR_Value(GPTIMR_RegDef_t* timer);
void Timer_Set_ARR(GPTIMR_RegDef_t* timer, uint32_t new_ARR);

void Timer_Clear_SR(GPTIMR_RegDef_t* timer);

void Stopwatch_Increment(time_counter_t* stopwatch);
void Stopwatch_Reset(time_counter_t* stopwatch);
void Stopwatch_To_String(time_counter_t* stopwatch, char* String);

uint8_t _check_Rollover(uint8_t* time_unit);
void TimerToStopwatch(GPTIMR_RegDef_t*, time_counter_t*);

//TODO Master Mode Options

#define	CLK_DIV_1 	0x0
#define CLK_DIV_2	0x1
#define CLK_DIV_4	0x2

#define CENTER_ALIGN_EDGE 	0x0
#define CENTER_ALIGN_DOWN 	0x1
#define CENTER_ALIGN_UP		0x2
#define CENTER_ALIGN_BOTH	0x3

#define COUNTING_UP 		0x0
#define COUNTING_DOWN 		0x1
#define COUNTING_UP_DOWN 	0x2

#define INPUT_CAPTURE 		0x4
#define INPUT_PWM			0x5

#define OUTPUT_FORCED 		0x6
#define OUTPUT_COMPARE 		0x7

#define MAX_ARR				0xFFFFFFFF




#endif /* TIMER_DRIVER_H_ */
