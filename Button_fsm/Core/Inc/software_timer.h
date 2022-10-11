/*
 * software_timer.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Guest_demo
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define TIME_CYCLE 10

extern int timer_flag;

void setTimer(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
