/*
 * game.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Lochi
 */

#ifndef INC_GAME_H_
#define INC_GAME_H_


#include "display.h"
#include "commands.h"
#include "Scheduler.h"
#include "Timer_Driver.h"
#include <strings.h>
#include "RNG.h"

#define MAX_ROUNDS	10


void BtnPress();

void Play_BtnPress();
void Start_BtnPress();
void Update();

void Command_State();
void Time_State();


void GameInit();

void RoundDisplay();
void TimeDisplay();
void TextDisplayDemo();

void GameStart();
void Game_Timer_Init();
void Game_Timer_Tick();
void Game_Timer_Start();
void Game_Timer_Stop();
void Game_Timer_Reset();

uint8_t GenerateScore();
void ScoreString(char*, uint8_t);

#endif /* INC_GAME_H_ */
