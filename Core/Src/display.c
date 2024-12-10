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

position_t DisplayCommand(char* command){
	position_t position;
	position.X = 10;
	position.Y = 10;
	LCD_Clear(0,LCD_COLOR_WHITE);
	DisplayInit();
	position = DisplayString(command, position);
	return position;
}

position_t DisplayText(char* String, position_t start_position){

}
//LCD_DisplayChar(100,140,'H');
position_t DisplayString(char* String, position_t start_position){
	uint16_t size = strlen(String);
	position_t Current_Position = start_position;
	for(uint16_t i = 0; i<size ;i++){
		if (String[i] != '\n') {
			LCD_DisplayChar(Current_Position.X, Current_Position.Y, String[i]);
		}
		Current_Position = FindNextCharPosition(Current_Position, start_position, String[i+1]);
	}
	return Current_Position;
}

position_t NewLine(position_t position){
	position.X = 10;
	position.Y = position.Y + DEFAULT_CHAR_HIGHT;
	return position;
}

position_t FindNextCharPosition(position_t Current, position_t Start, char NextChar){
	if (((Current.X + DEFAULT_CHAR_WIDTH) > SCREEN_CHAR_WIDTH) ||
			(NextChar == '\n')) {
		Current.X = Start.X;
		Current.Y = Current.Y + DEFAULT_CHAR_HIGHT;
	} else {
		Current.X = Current.X + DEFAULT_CHAR_WIDTH;
	}
	return Current;
}

uint16_t FindCenterOfString(char* String){
	return 0;
}
