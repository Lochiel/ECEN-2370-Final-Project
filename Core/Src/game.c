/*
 * game.c
 *
 *  Created on: Dec 3, 2024
 *      Author: Lochi
 */

#include "game.h"

#define STATE_START			0
#define	STATE_COMMAND		1
#define STATE_TIME			2


uint8_t gamestate = STATE_START;
time_counter_t stopwatch;
RNG_HandleTypeDef hrng;


//#TODO RNG Setup
/*
 *       (#) Enable the RNG controller clock using __HAL_RCC_RNG_CLK_ENABLE() macro
          in HAL_RNG_MspInit().
      (#) Activate the RNG peripheral using HAL_RNG_Init() function.
      (#) Wait until the 32 bit Random Number Generator contains a valid
          random data using (polling/interrupt) mode.
      (#) Get the 32 bit random number using HAL_RNG_GenerateRandomNumber() function.
 *
 */
void GameInit(){
	Stopwatch_Reset(&stopwatch);
	Game_Timer_Init();
	__HAL_RCC_RNG_CLK_ENABLE();
	HAL_RNG_Init(hrng);
}

void BtnPress(){
	switch(gamestate){
	case STATE_START:
	case STATE_TIME:
		Command_State();
		break;
	case STATE_COMMAND:
		Time_State();
		break;
	}
	removeSchedulerEvent(EVENT_BUTTON);
}

void Command_State(){
	gamestate = STATE_COMMAND;
	Game_Timer_Reset();
	Game_Timer_Start();
	TextDisplayDemo();
}

void Time_State(){
	gamestate = STATE_TIME;
	Game_Timer_Stop();
//	TimerToStopwatch(TIM_7, &stopwatch);
	TimeDisplay();
}

void TimeDisplay(){
	position_t position;
	char timestring[MAX_CHAR_LENGTH];
	Stopwatch_To_String(&stopwatch, timestring);
	position = DisplayCommand(timestring);
	position = NewLine(position);
	DisplayString("has past since you started", position);
}

void TextDisplayDemo(){
	char Command[MAX_CHAR_LENGTH];
	GetCommand(Command);
	DisplayCommand(Command);
}


void Game_Timer_Init(){
	GPTimer_Config_t timer;
	timer.ClockDivision = CLK_DIV_1;
	timer.Prescaler = 96;
	timer.CenterAlignedMode = COUNTING_UP;
	timer.ARR_Buffer_Enabled = DISABLE;
	timer.CountDownModeEnabled = DISABLE;
	timer.InterruptUpdateEnabled = ENABLE;
	timer.DisableUpdateEvent = DISABLE;
	timer.OnePulseModeEnabled = DISABLE;
	timer.MasterMode = DISABLE;

	uint32_t arr = 0xFF50;
	timer.ARR = arr;

	Timer_Init(TIM_7, timer);
}

void Game_Timer_Tick(){
	Stopwatch_Increment(&stopwatch);
}

void Game_Timer_Start(){
	Timer_Start(TIM_7);
}

void Game_Timer_Stop(){
	Timer_Stop(TIM_7);
}

void Game_Timer_Reset(){
	Timer_Reset(TIM_7);
}


