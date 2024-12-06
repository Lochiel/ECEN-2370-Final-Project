/*
 * display.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Lochi
 */

#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

#include "LCD_Driver.h"
#include "stm32.h"
#include <string.h>
#include "commands.h"

#define DEFAULT_CHAR_WIDTH	15


typedef struct{
	uint16_t X;
	uint16_t Y;
}position_t;

void DisplayInit();

void DisplayCommand(char* command);
void DisplayString(char* String, position_t start_position);

position_t FindNextCharPosition(position_t Current, position_t Start);

uint16_t FindCenterOfString(char* String);

#endif /* INC_DISPLAY_H_ */
