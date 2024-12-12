/*
 * comamnds.c
 *
 *  Created on: Dec 3, 2024
 *      Author: Lochi
 */

#include "commands.h"


char QuoteArray[3][MAX_CHAR_LENGTH] =
							{
							"Authority should derive from the consent of the governed, not from the threat of force! -- Barbie",
							"Some of those that work forces, are the same that burn crosses",
							"Deny Defend Depose"};

char CommandArray[NUM_OF_COMMANDS][MAX_CHAR_LENGTH] =
							{"Simon Says:\n Press the Blue Button",
							"Simon Says:\n Pay for his lunch",
							"Simon Says:\n Press the Red Arrow",
							"Simon Says:\n Shake the device",
							"Simon Says:\n Spin in place",
							"Simon is to busy singing to himself to say anything",
							"Simon doesn't say anything, but makes it clear that you already know what you need to do",
							"Simon Says:\n Will no one rid me of this turbulent priest?",
							"Simon insults you because your Loyalty score is too low",
							"Simon Says:\n If you do what I say, I'll hurt people. If you don't, I'll hurt you",
							"Simon Says:\n Bop It! Twist It! Pull It!",
							"Simon Says:\n Press the Black Button",
							"Simon Says:\n Put your left leg in",
							"Simon Says:\n Shake it all about",
							"Simon Says:\n Donate to his cause",
							"Simon Says:\n Press the Green Circle",
							"Simon Says:\n Press the Golden Triangle",
							"Simon Says:\n Wash your hands after using the restroom",
							"Simon Says:\n The social hierarchy reflects natural order"};

//TODO: STUB
void GetCommand(char *ReturnCommand){
	uint32_t Command_ID;
	Command_ID = RandNum() % NUM_OF_COMMANDS;
	strcpy(ReturnCommand, CommandArray[Command_ID]);
}

void GetQuote(char *ReturnCommand){
	uint32_t Command_ID;
	Command_ID = RandNum() % 3;
	strcpy(ReturnCommand, QuoteArray[Command_ID]);
//	ReturnCommand = CommandArray[Command_ID];
}

