/*
 * global.h
 *
 *  Created on: Oct 4, 2022
 *      Author: Guest_demo
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"

#define	LED_RED 	0
#define LED_GREEN 	1
#define LED_YELLOW 	2

#define INIT 			1
#define AUTO_RED 		2
#define AUTO_GREEN 		3
#define AUTO_YELLOW 	4

#define MAN_RED			12
#define	MAN_GREEN		13
#define MAN_YELLOW		14

#define TIMER_BUTTON 	0
#define TIMER_SOFTWARE 	1

extern int status;

#endif /* INC_GLOBAL_H_ */
