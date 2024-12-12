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

enum Game_State {
	Start,
	Play,
	Score
};

enum Game_State gamestate = Start;
time_counter_t stopwatch;
uint8_t game_round = 0;
uint8_t score = 0;

void GameInit(){
	Stopwatch_Reset(&stopwatch);
	Game_Timer_Init();
	RNG_Init();
}

void BtnPress(){
	switch(gamestate){
	case Start:
	case Score:
		Start_BtnPress();
		break;
	case Play:
		Play_BtnPress();
		break;
	}
	removeSchedulerEvent(EVENT_BUTTON);
}

void Play_BtnPress(){
	if (game_round == MAX_ROUNDS){
		gamestate = Score;
		game_round = 0;
		score = GenerateScore();
	} else {
		game_round += 1;
	}
	addSchedulerEvent(EVENT_UPDATE);
	return;
}

void Start_BtnPress(){
	gamestate = Play;
	addSchedulerEvent(EVENT_UPDATE);
}

void Update(){
	switch(gamestate){
		case Start:
			GameStart();
			break;
		case Score:
			Time_State();
			break;
		case Play:
			Command_State();
			break;
	}
	removeSchedulerEvent(EVENT_UPDATE);
}

void UpdateClock(){
	if (gamestate == Score){
		Time_State();
	}
	removeSchedulerEvent(EVENT_TICK);
}

void GameStart(){
	gamestate = Play;
	Game_Timer_Reset();
	Game_Timer_Start();
	Command_State();
}
void Command_State(){
	Game_Timer_Start();
	RoundDisplay();
}

void Time_State(){
	gamestate = Score;
//	Game_Timer_Stop();
//	TimerToStopwatch(TIM_7, &stopwatch);
	TimeDisplay();
}

void TimeDisplay(){
	position_t position;
	char timestring[MAX_CHAR_LENGTH];
	char Score_String[MAX_CHAR_LENGTH];
	Stopwatch_To_String(&stopwatch, timestring);
	ScoreString(Score_String, score);
	position = DisplayCommand(timestring);
	position = NewLine(position);
	position = DisplayString("has past since you started", position);
	position = NewLine(position);
	DisplayString(Score_String, position);
}

void RoundDisplay(){
	position_t position;
	char Round_String[MAX_CHAR_LENGTH];
	char Command[MAX_CHAR_LENGTH];
	sprintf(Round_String,"Round: %d\n", game_round);
	GetCommand(Command);
	position = DisplayCommand(Round_String);
	position = NewLine(position);
	DisplayString(Command, position);
}

void StartScreenDisplay(){
	char Command[MAX_CHAR_LENGTH];
	GetQuote(Command);
	DisplayCommand(Command);
}

void TextDisplayDemo(){
	char Command[MAX_CHAR_LENGTH];
	GetCommand(Command);
	DisplayCommand(Command);
}


void Game_Timer_Init(){
	GPTimer_Config_t timer;
	timer.ClockDivision = CLK_DIV_1;
	timer.Prescaler = 1282;
	timer.CenterAlignedMode = COUNTING_UP;
	timer.ARR_Buffer_Enabled = DISABLE;
	timer.CountDownModeEnabled = DISABLE;
	timer.InterruptUpdateEnabled = ENABLE;
	timer.DisableUpdateEvent = DISABLE;
	timer.OnePulseModeEnabled = DISABLE;
	timer.MasterMode = DISABLE;

	uint32_t arr = 0xFFF2;
	timer.ARR = arr;

	Timer_Init(TIM_7, timer);
}

void Game_Timer_Tick(){
	Stopwatch_Increment(&stopwatch);
	addSchedulerEvent(EVENT_TICK);
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

uint8_t GenerateScore(){
	uint32_t score = RandNum();
	uint8_t rtn_score = (uint8_t)score;
	rtn_score = rtn_score%64;
	return rtn_score;
}

void ScoreString(char* String, uint8_t score){
	sprintf(String, "Score: %d\n", score);
}

