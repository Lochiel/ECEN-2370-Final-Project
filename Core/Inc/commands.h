/*
 * commands.h
 *
 *  Created on: Dec 3, 2024
 *      Author: Lochi
 */

#ifndef INC_COMMANDS_H_
#define INC_COMMANDS_H_

#include <stdlib.h>
#include "stm32f4xx_hal.h"
#include <string.h>
#include "RNG.h"

#define NUM_OF_COMMANDS		19
#define MAX_CHAR_LENGTH		128

void GetCommand(char *ReturnCommand);
void GetQuote(char *ReturnCommand);

#endif /* INC_COMMANDS_H_ */
