/*
 * fsm_manual.c
 *
 *  Created on: 11 thg 10, 2022
 *      Author: Guest_demo
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch (status){
		case MAN_RED:
			//TODO
			turnLightOn(LED_RED);
			if (timer_flag == 1){
				status = AUTO_RED;
				setTimer(5000);
			}
			if (isButton1Pressed()){
				status = MAN_GREEN;
				setTimer(10000);
			}
			break;
		case MAN_GREEN:
			//TODO
			turnLightOn(LED_GREEN);
			if (timer_flag == 1){
				status = AUTO_GREEN;
				setTimer(3000);
			}
			if (isButton1Pressed()){
				status = MAN_YELLOW;
				setTimer(10000);
			}
			break;
		case MAN_YELLOW:
			//TODO
			turnLightOn(LED_YELLOW);
			if (timer_flag == 1){
				status = AUTO_YELLOW;
				setTimer(3000);
			}
			if (isButton1Pressed()){
				status = MAN_RED;
				setTimer(10000);
			}
			break;
		default: break;
	}
}
