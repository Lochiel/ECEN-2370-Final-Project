/*
 * comamnds.c
 *
 *  Created on: Dec 3, 2024
 *      Author: Lochi
 */

#include "commands.h"


char CommandArray[NUM_OF_COMMANDS][MAX_CHAR_LENGTH] =
							{"Test Command",
							"Authority should derive from the consent of the governed, not from the threat of force! -- Barbie",
							"You should take a nap",
							"Yet Another Test Text",
							"....|....|....|....|....|....|....|",
							"Some of those that work forces, are the same that burn crosses"};

//TODO: STUB
void GetCommand(char *ReturnCommand){
	uint16_t Command_ID;
	Command_ID = rand() % NUM_OF_COMMANDS;
//	strcpy(ReturnCommand, "Test Command");
//	ReturnCommand = "Test Command";
	strcpy(ReturnCommand, CommandArray[Command_ID]);
//	ReturnCommand = CommandArray[Command_ID];
}

