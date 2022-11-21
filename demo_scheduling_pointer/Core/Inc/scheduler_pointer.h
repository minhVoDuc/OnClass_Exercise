/*
 * scheduler_pointer.h
 *
 *  Created on: Nov 14, 2022
 *      Author: Guest_demo
 */

#ifndef INC_SCHEDULER_POINTER_H_
#define INC_SCHEDULER_POINTER_H_

#include "sched_task.h"

typedef struct {
	uint32_t cur_size;
	schedTask *head;
} schedList;

#define SCH_MAX_TASKS 	10
#define NO_TASK_ID		0
#define RETURN_ERROR	0
#define RETURN_NORMAL	1

void SCH_Init();
void SCH_Start();
void SCH_Add_To_List(schedTask *task);
schedTask* SCH_Get_From_List();
void SCH_Dispatch_Tasks(void);
void SCH_Update(void);
void SCH_Report_Status(void);
void SCH_Go_To_Sleep();
void SCH_Add_Task(void (*pTask)(void), const uint32_t Delay, const uint32_t Period);
uint32_t SCH_Delete_Task();

#endif /* INC_SCHEDULER_POINTER_H_ */
