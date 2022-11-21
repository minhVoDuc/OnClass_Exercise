/*
 * sched_task.c
 *
 *  Created on: 20 thg 11, 2022
 *      Author: Guest_demo
 */

#include "sched_task.h"

schedTask* make_task(void (*pTask)(void), const uint32_t DELAY, const uint32_t PERIOD){
	schedTask *task = malloc(sizeof (schedTask));
	task->pTask = pTask;
	task->Delay = DELAY / TICK;
	task->Period = PERIOD / TICK;
	task->RunMe = 0;
	task->nextTask = NULL;
	return task;
}

void delete_task(schedTask *task){
	free(task);
}
