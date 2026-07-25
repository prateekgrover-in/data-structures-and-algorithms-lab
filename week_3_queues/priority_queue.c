#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "priority_queue.h"

MultiQ createMQ(int num){
    struct queue * new_q_arr = malloc(sizeof(Queue) * num);
    for (int i = 0; i < num; i++){
        struct queue new_q;
        new_q.first = NULL;
        new_q.last = NULL;
        new_q.size = 0;
        new_q_arr[i] = new_q;
    }
    MultiQ new_multi_q;
    new_multi_q.size = num;
    new_multi_q.q_arr = new_q_arr;
    return new_multi_q;
}

MultiQ addMQ(MultiQ mq, Task t){
    void * element;
    element = t.task_id;
    mq.q_arr[t.pri - 1] = addQ(mq.q_arr[t.pri - 1], element);
    return mq;
}

Task nextMQ(MultiQ mq){
	if (isEmptyMQ(mq)) {
		Task empty_task;
		empty_task.task_id = -1;
		empty_task.pri = -1;
		return empty_task;
	}
	else{
		int i = mq.size - 1;
		while(isEmptyQ(mq.q_arr[i])){
            i--;
        }
        struct queue * cur_q_arr = mq.q_arr;
        // Task *(task_pointer) = mq.q_arr[i].first -> data_ptr;
        Task next_task;
        next_task.task_id = mq.q_arr[i].first -> data_ptr;
        next_task.pri = i;
        return next_task;
	}
}

bool isEmptyMQ(MultiQ mq){
	for (int i = mq.size - 1; i >= 0; i--){
		if (isEmptyQ(mq.q_arr[i])){
            continue;
		}
		else{
			return false;
		}
	}
	return true;
}

MultiQ delNextMQ (MultiQ mq) { 
	if (isEmptyMQ(mq)){
		return mq;
	}
	else{
		int i = maxPriority - 1;
		while (isEmptyQ(mq.q_arr[i])){
            i--;
        }
		mq.q_arr[i] = delQ(mq.q_arr[i]);
		return mq;
	}
}

int sizeMQ (MultiQ mq) {
	int size = 0;
	for (int i = mq.size - 1; i >= 0; i--){
		size += lengthQ(mq.q_arr[i]);
	}
	return size;
}

int sizeMQbyPriority(MultiQ mq, Priority p){
	return lengthQ(mq.q_arr[p-1]);
}


Queue getQueueFromMQ(MultiQ mq, Priority p){
	return mq.q_arr[p-1];
}

int printMQ(Queue q) {
    struct node * cur = q.first;
    printf("[");
    while (cur -> next != NULL){
        printf("%d, ", cur -> data_ptr);
        cur = cur -> next;
    }
    printf("%d]", cur -> data_ptr);
    return 0;
}
