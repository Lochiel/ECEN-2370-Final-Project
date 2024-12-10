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
#define DEFAULT_CHAR_HIGHT	20
#define SCREEN_CHAR_WIDTH	225


typedef struct{
	uint16_t X;
	uint16_t Y;
}position_t;

void DisplayInit();

position_t DisplayCommand(char* command);
position_t DisplayText(char* String, position_t start_position);
position_t DisplayString(char* String, position_t start_position);
position_t NewLine(position_t position);

position_t FindNextCharPosition(position_t Current, position_t Start, char NextChar);

uint16_t FindCenterOfString(char* String);

#endif /* INC_DISPLAY_H_ */
