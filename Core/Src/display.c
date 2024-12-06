/*
 * display.c
 *
 *  Created on: Dec 3, 2024
 *      Author: Lochi
 */

#include "display.h"

void DisplayInit(){
	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);
}

void DisplayCommand(char* command){
	position_t position;
	position.X = 10;
	position.Y = 10;
	DisplayString(command, position);
}

//LCD_DisplayChar(100,140,'H');
void DisplayString(char* String, position_t start_position){
	uint16_t size = strlen(String);
	position_t Current_Position = start_position;
	for(uint16_t i = 0; i<size ;i++){
		LCD_DisplayChar(Current_Position.X, Current_Position.Y, String[i]);
		Current_Position = FindNextCharPosition(Current_Position, start_position);
	}
}

position_t FindNextCharPosition(position_t Current, position_t Start){
	if ((Current.X + DEFAULT_CHAR_WIDTH) > LCD_PIXEL_WIDTH){
		Current.X = Start.X;
		Current.Y = Current.Y + DEFAULT_CHAR_WIDTH;
	} else {
		Current.X = Current.X + DEFAULT_CHAR_WIDTH;
	}
	return Current;
}

uint16_t FindCenterOfString(char* String){
	return 0;
}
