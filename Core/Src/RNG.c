/*
 * RNG.c
 *
 *  Created on: Dec 11, 2024
 *      Author: Lochi
 */

#include "RNG.h"


RNG_HandleTypeDef hrng;

void RNG_Init(){
	__HAL_RCC_RNG_CLK_ENABLE();
	hrng.Instance = RNG;
	HAL_RNG_Init(&hrng);
}

uint32_t RandNum(){
	uint32_t number = 0;
	HAL_RNG_GenerateRandomNumber(&hrng, &number);
	return number;
}
