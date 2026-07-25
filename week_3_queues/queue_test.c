/* driver_que.c */

#include "queue.h"

int main() {

    Queue q = newQ();
    q.size = 0;
    q.first = NULL;
    q.last = NULL;

    printf("Checking if Queue is empty using isEmptyQ() function : ");
    printf(isEmptyQ(q) ? "True \n" : "False \n");

	void * e1;
    void * e2;
    void * e3;

    printf("Adding three strings to the queue in the following order: ");

	e1 = "abc";
	e2 = "xyz";
    e3 = "ghi";

    printf("[%s, %s, %s] \n", e1, e2, e3);

	q = addQ(q, e1);
	q = addQ(q, e2);
    q = addQ(q, e3);

    printf("Length of Queue is : ");
    printf("%d  \n", lengthQ(q));
    printf("Checking if Queue is empty using isEmptyQ() function: ");
    printf(isEmptyQ(q) ? "true \n" : "false \n");
    printf("Deleting element from the start using delQ() function  \n");
    q = delQ(q);
    printf("Status of Queue is : [");
    printQ(q);
    printf("]");
	return 0;
}