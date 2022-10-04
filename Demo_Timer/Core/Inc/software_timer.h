/*
 * software_timer.h
 *
 *  Created on: Sep 26, 2022
 *      Author: Guest_demo
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[5];

void setTimer(int index, int duration);
void timerRun(int index);

#endif /* INC_SOFTWARE_TIMER_H_ */
