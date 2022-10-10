/*
 * software_timer.c
 *
 *  Created on: Sep 26, 2022
 *      Author: Guest_demo
 */

#include "software_timer.h"

#define MAX_TIMER 2

int timer_counter[MAX_TIMER] = {0, 0};
int timer_flag[MAX_TIMER] = {0, 0};

void setTimer(int index, int duration){
	timer_counter[index] = duration;
	timer_flag[index] = 0;
}

void timerRun(){
	for (int i=0; i<MAX_TIMER; i++){
		if (timer_counter[i] > 0){
			timer_counter[i]--;
			if (timer_counter[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}
