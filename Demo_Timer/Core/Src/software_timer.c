/*
 * software_timer.c
 *
 *  Created on: Sep 26, 2022
 *      Author: Guest_demo
 */

#include "software_timer.h"

int timer_counter[5] = {0, 0, 0, 0, 0};
int timer_flag[5] = {0, 0, 0, 0, 0};

void setTimer(int index, int duration){
	timer_counter[index] = duration;
	timer_flag[index] = 0;
}

void timerRun(int index){
	if (timer_counter[index] > 0){
		timer_counter[index]--;
		if (timer_counter[index] <= 0){
			timer_flag[index] = 1;
		}
	}
}
