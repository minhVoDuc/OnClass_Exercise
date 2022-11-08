/*
 * software_timer.h
 *
 *  Created on: Nov 7, 2022
 *      Author: Guest_demo
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define MAX_TIMER 	1
#define CYCLE 		10

#define TIMER_1		0

void set_timer(int index, int duration);
int check_timer_flag(int index);
void run_timer();

#endif /* INC_SOFTWARE_TIMER_H_ */
