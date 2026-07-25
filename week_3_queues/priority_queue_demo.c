/* testMultiq.c */

#include "priority_queue.h"

int main(int argc, char *argv[]) {

	FILE * f = fopen(argv[1], "r");
	MultiQ mq = createMQ(10);
    printf("Checking if Multiqueue is Empty : ");
    printf(isEmptyMQ(mq) ? "True \n" : "False \n");
	int task_id = -1; int pri = -1;
	Task t;
	while (!feof(f)) {
		fscanf(f, "%d,%d", &task_id, &pri);
		t.pri = pri;
		t.task_id = task_id;
        //printf("Task ID: %d, Priority: %d \n", t.task_id, t.pri);
		mq = addMQ(mq, t);
	}
	fclose(f);
	printf("Checking if Multiqueue is Empty : ");
    printf(isEmptyMQ(mq) ? "True \n" : "False \n");
    printf("Size of Multiqueue is: %d \n", sizeMQ(mq));
    for (int i = 1; i <= 10; i++){
        printf("Size of Priority %d Queue is: %d \n", i, sizeMQbyPriority(mq, i));
    }
    printf("Printing elements of Queue with Greatest Priority : \n");
    Queue pri_ten_queue = getQueueFromMQ(mq, 10);

    int y = printMQ(pri_ten_queue);

    Task next_task = nextMQ(mq);
    printf("\nNext Element's Task ID : %d, Priority : %d", next_task.task_id, next_task.pri + 1);
    
    printf("\nDeleting next element : \n");
    mq = delNextMQ(mq);
    
    printf("Current status of Greatest Priority Queue: \n");
    pri_ten_queue = getQueueFromMQ(mq, 10);
    y = printMQ(pri_ten_queue);
    return 0;
}