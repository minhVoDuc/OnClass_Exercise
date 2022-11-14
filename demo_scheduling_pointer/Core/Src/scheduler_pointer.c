/*
 * scheduler_pointer.c
 *
 *  Created on: Nov 14, 2022
 *      Author: Guest_demo
 */

#include "scheduler_pointer.h"
#include "main.h"
#include "global.h"

//the array of tasks
schedTask SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task;

void SCH_Init(){
	current_index_task = 0;
}

void SCH_Start(){

}

void SCH_Update(void){
	//NOTE: calculations are in *TICKS* (not miliseconds)
	for (int i = 0; i < current_index_task; i++){
		//check if there is a task at this location
		if (SCH_tasks_G[i].pTask){
			if (SCH_tasks_G[i].Delay == 0){
				//the task is due to run
				SCH_tasks_G[i].RunMe = 1; //active flag 'RunMe'
				if (SCH_tasks_G[i].Period){
					//schedule periodic tasks to run again
					SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
				}

			}
			else {
				//not yet ready to run: just decrease the delay
				SCH_tasks_G[i].Delay -= 1;
			}
		}
	}
}

void SCH_Dispatch_Tasks(void){
	//dispatching (running) the next task (if one is ready)
	for (int i = 0; i < current_index_task; i++){
		if (SCH_tasks_G[i].RunMe > 0){
			(*SCH_tasks_G[i].pTask)(); 	//run the taskz
			SCH_tasks_G[i].RunMe = 0; 	//reset RunMe flag
			//periodic tasks will auto run again
			//if it's a 'oneshot' task, remove it from the array
			if (SCH_tasks_G[i].Period == 0){
				SCH_Delete_Task(i);
			}
		}
	}
//	SCH_Report_Status();
//	SCH_Go_To_Sleep();
}

void SCH_Report_Status(void){

}

void SCH_Add_Task(void (*pTask)(void), const uint32_t DELAY, const uint32_t PERIOD){
	//check if reaching the end of the array
	if (current_index_task == SCH_MAX_TASKS){
		//array is full, set the global error variable
//		Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
		return; // Also return an error code
	}
	//otherwise, index is valid - there's a space in task array
	SCH_tasks_G[current_index_task].pTask = pTask;
	SCH_tasks_G[current_index_task].Delay = DELAY / TICK;
	SCH_tasks_G[current_index_task].Period = PERIOD / TICK;
	SCH_tasks_G[current_index_task].RunMe = 0;

	SCH_tasks_G[current_index_task].TaskID = current_index_task;
	current_index_task++;

}

uint32_t SCH_Delete_Task(const uint32_t index){
	uint32_t Return_code;
	if (SCH_tasks_G[index].pTask == 0){
		//no task at this location
		//set the global error variable
//		Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
		Return_code = RETURN_ERROR; //return an error code
	}
	else {
		Return_code = RETURN_NORMAL;
	}
	SCH_tasks_G[index].pTask = 0x0000;
	SCH_tasks_G[index].Delay = 0;
	SCH_tasks_G[index].Period = 0;
	SCH_tasks_G[index].RunMe = 0;
	return Return_code; //return position of task (to allow deletion)
}
