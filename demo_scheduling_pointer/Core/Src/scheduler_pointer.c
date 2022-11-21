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
schedList SCH_tasks_G;

void SCH_Init(){
	SCH_tasks_G.cur_size = 0;
	SCH_tasks_G.head = NULL;
}

void SCH_Start(){

}

void SCH_Add_To_List(schedTask *task){
	SCH_tasks_G.cur_size++;
	//add first task
	if (SCH_tasks_G.cur_size == 1){
		SCH_tasks_G.head = task;
		return;
	}
	uint32_t time_interval = SCH_tasks_G.head->Delay;
	schedTask *currTask = SCH_tasks_G.head,
			  *prevTask = NULL;
	while(currTask) {
		if (task->Delay < time_interval) break;
		prevTask = currTask;
		currTask = currTask->nextTask;
		if (currTask != NULL) time_interval += currTask->Delay;
	}
	if (prevTask == NULL) { //before first element of the list
		SCH_tasks_G.head->Delay -= task->Delay;
		task->nextTask = SCH_tasks_G.head;
		SCH_tasks_G.head = task;
		return;
	}
	if (currTask == NULL) { //after last element of the list
		task->Delay -= time_interval;
	}
	else { //added task is between 2 elements of the list
		task->Delay -= (time_interval - currTask->Delay);
	}
	task->nextTask = currTask;
	prevTask->nextTask = task;
}

schedTask* SCH_Get_From_List(){
	schedTask *task = SCH_tasks_G.head; //get first element of the list and soft remove it
	SCH_tasks_G.head = task->nextTask;
	task->nextTask = NULL;
	SCH_tasks_G.cur_size--;
	return task;
}

void SCH_Update(void){
	//NOTE: calculations are in *TICKS* (not miliseconds)
	if (SCH_tasks_G.head){
		if (SCH_tasks_G.head->Delay == 0) {
			//the task is due to run
			SCH_tasks_G.head->RunMe = 1; //active flag 'RunMe'
			if (SCH_tasks_G.head->Period){
				//schedule periodic tasks to run again
				SCH_tasks_G.head->Delay = SCH_tasks_G.head->Period;
			}
		}
		else {
			//not yet ready to run: just decrease the delay
			SCH_tasks_G.head->Delay -= 1;
		}
	}
}

void SCH_Dispatch_Tasks(void){
	//dispatching (running) the next task (if one is ready)
	if (SCH_tasks_G.head->RunMe > 0) {
		(*SCH_tasks_G.head->pTask)(); //run the task
		SCH_tasks_G.head->RunMe = 0; //reset RunMe flag
		//periodic tasks will auto run again
		//if it's a 'oneshot' task, remove it from the array
		schedTask *reTask = SCH_Get_From_List();
		if (SCH_tasks_G.head->Period != 0){
			SCH_Add_To_List(reTask);
		}
		else {
			SCH_Delete_Task(reTask);
		}
	}
}

void SCH_Report_Status(void){

}

void SCH_Add_Task(void (*pTask)(void), const uint32_t DELAY, const uint32_t PERIOD){
	//check if reaching the end of the list
	if (SCH_tasks_G.cur_size == SCH_MAX_TASKS){
		return;
	}
	//otherwise, index is valid - there's a space in task array
	schedTask *newTask = make_task(pTask, DELAY, PERIOD);
	//add to list
	SCH_Add_To_List(newTask);
}

uint32_t SCH_Delete_Task(){ //delete first task of list
	uint32_t Return_code;
	if (SCH_tasks_G.head == NULL) { //if list is empty
		Return_code = RETURN_ERROR;
	}
	else {
		Return_code = RETURN_NORMAL;
		schedTask *delTask = SCH_Get_From_List();
		delete_task(delTask);
	}
	return Return_code;
}
