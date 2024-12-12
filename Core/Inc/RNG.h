/*
 * RNG.h
 *
 *  Created on: Dec 11, 2024
 *      Author: Lochi
 */

#ifndef INC_RNG_H_
#define INC_RNG_H_

#include "stm32f4xx_hal.h"

void RNG_Init();
uint32_t RandNum();


#endif /* INC_RNG_H_ */
