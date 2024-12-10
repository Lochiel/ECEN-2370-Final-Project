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

void BtnPress();

void Command_State();
void Time_State();


void GameInit();

void TimeDisplay();
void TextDisplayDemo();

void Game_Timer_Init();
void Game_Timer_Tick();
void Game_Timer_Start();
void Game_Timer_Stop();
void Game_Timer_Reset();


#endif /* INC_GAME_H_ */
