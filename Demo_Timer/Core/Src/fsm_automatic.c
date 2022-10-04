/*
 * fsm_automatic.c
 *
 *  Created on: 4 thg 10, 2022
 *      Author: Guest_demo
 */

#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch (status){
		case INIT:
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin | LED_GREEN_Pin | LED_YELLOW_Pin, 1);

			status = AUTO_GREEN;
			setTimer(LED_INDEX, 300);
			break;
		case AUTO_RED:
			//TODO
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 0);

			if (timer_flag[LED_INDEX] == 1){
				status = AUTO_GREEN;
				setTimer(LED_INDEX, 300);
			}
			break;
		case AUTO_GREEN:
			//TODO
			HAL_GPIO_WritePin(GPIOA, LED_RED_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 0);

			if (timer_flag[LED_INDEX] == 1){
				status = AUTO_YELLOW;
				setTimer(LED_INDEX, 200);
			}
			break;
		case AUTO_YELLOW:
			//TODO
			HAL_GPIO_WritePin(GPIOA, LED_GREEN_Pin, 1);
			HAL_GPIO_WritePin(GPIOA, LED_YELLOW_Pin, 0);

			if (timer_flag[LED_INDEX] == 1){
				status = AUTO_RED;
				setTimer(LED_INDEX, 500);
			}
			break;
		default: break;
	}
}
