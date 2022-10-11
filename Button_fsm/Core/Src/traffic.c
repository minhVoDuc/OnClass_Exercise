/*
 * traffic.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Guest_demo
 */

#include "traffic.h"

void turnLightOn(int led){
	switch(led){
		case LED_RED:
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);
			break;
		case LED_GREEN:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 0);
			break;
		case LED_YELLOW:
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 0);
			break;
		default:
			break;
	}
}

void clearLight(){
	HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | LED_GREEN_Pin | LED_YELLOW_Pin, 1);
}
