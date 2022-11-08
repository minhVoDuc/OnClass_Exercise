/*
 * scheduler.h
 *
 *  Created on: 7 thg 11, 2022
 *      Author: Guest_demo
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include <stdint.h>

typedef struct {
	void 	(*pTask)(void); //pointer to the task (must be a 'void(void)' function)
	uint32_t 	Delay; 		//delay (ticks) until the function will be first run
	uint32_t	Period; 	//interval (ticks) between subsequent runs
	uint8_t	RunMe; 			//incremented (by scheduler) when task is due to execute

	uint32_t TaskID;
} schedTask;

#define SCH_MAX_TASKS 	10
#define NO_TASK_ID		0
#define RETURN_ERROR	0
#define RETURN_NORMAL	1

#define TICK			10

void SCH_Init();
void SCH_Start();
void SCH_Dispatch_Tasks(void);
void SCH_Update(void);
void SCH_Report_Status(void);
void SCH_Go_To_Sleep();
void SCH_Add_Task(void (*pTask)(void), const uint32_t Delay, const uint32_t Period);
uint32_t SCH_Delete_Task(const uint32_t TASK_INDEX);



#endif /* INC_SCHEDULER_H_ */
