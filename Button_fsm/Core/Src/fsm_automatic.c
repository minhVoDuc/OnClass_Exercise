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
			clearLight();
			status = AUTO_RED;
			setTimer(5000);
			break;
		case AUTO_RED:
			//TODO
			turnLightOn(LED_RED);
			if (timer_flag == 1){
				status = AUTO_GREEN;
				setTimer(3000);
			}
			if (isButton1Pressed()){
				status = MAN_RED;
				setTimer(10000);
			}
			break;
		case AUTO_GREEN:
			//TODO
			turnLightOn(LED_GREEN);
			if (timer_flag == 1){
				status = AUTO_YELLOW;
				setTimer(2000);
			}
			break;
		case AUTO_YELLOW:
			//TODO
			turnLightOn(LED_YELLOW);
			if (timer_flag == 1){
				status = AUTO_RED;
				setTimer(5000);
			}
			break;
		default: break;
	}
}
