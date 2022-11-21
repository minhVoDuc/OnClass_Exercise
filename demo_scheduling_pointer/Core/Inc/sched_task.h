/*
 * sched_task.h
 *
 *  Created on: 20 thg 11, 2022
 *      Author: Guest_demo
 */

#ifndef INC_SCHED_TASK_H_
#define INC_SCHED_TASK_H_

#include <stdlib.h>
#include <stdint.h>

#define TICK			10

typedef struct {
	void 	(*pTask)(void); //pointer to the task (must be a 'void(void)' function)
	uint32_t 	Delay; 		//delay (ticks) until the function will be first run
	uint32_t	Period; 	//interval (ticks) between subsequent runs
	uint8_t	RunMe; 			//incremented (by scheduler) when task is due to execute

	uint32_t TaskID;
	struct schedTask *nextTask;
} schedTask;

schedTask* make_task(void (*pTask)(void), const uint32_t DELAY, const uint32_t PERIOD);
void delete_task(schedTask *task);

#endif /* INC_SCHED_TASK_H_ */
