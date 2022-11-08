/*
 * software_timer.c
 *
 *  Created on: Nov 7, 2022
 *      Author: Guest_demo
 */

#include "software_timer.h"

int TimerCounter[MAX_TIMER] = {0};
int TimerFlag[MAX_TIMER] = {0};

void set_timer(int index, int duration){
	TimerCounter[index] = duration / CYCLE;
	TimerFlag[index] = 0;
}

int check_timer_flag(int index){
	if (TimerFlag[index] == 1){
		TimerFlag[index] = 0;
		return 1;
	}
	return 0;
}

void run_timer(){
	for (int i=0; i < MAX_TIMER; i++){
		if (TimerCounter[i] >= 0){
			TimerCounter[i]--;
			if (TimerCounter[i] <= 0){
				TimerFlag[i] = 1;
			}
		}
	}
}
