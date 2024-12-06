/*
 * game.c
 *
 *  Created on: Dec 3, 2024
 *      Author: Lochi
 */

#include "game.h"

void TextDisplayDemo(){
	char Command[MAX_CHAR_LENGTH];
	GetCommand(Command);
	LCD_Clear(0,LCD_COLOR_WHITE);
	DisplayInit();
//	DisplayCommand("12345");
	DisplayCommand(Command);
	removeSchedulerEvent(EVENT_NEW_COMMAND);
}
