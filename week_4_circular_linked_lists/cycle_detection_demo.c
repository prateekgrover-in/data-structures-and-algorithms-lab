  
#include "cycle_detection.h"
#include <sys/time.h>

long long heapspace = 0;

void * myalloc (int x){
	heapspace += x;
	int * asd = (int*) malloc(x+4);
	*asd = x;
	return (((void*)asd) + 4);
}

void myfree (void * x){
	int* toread = (int*)(x-4);
	int size = * toread;
	heapspace -= size;
	free (toread);
}

struct linkedList * makeCircularList(struct linkedList * head){
    if (detectCycle(head) == 1){
       struct node * start_node = start_of_loop(head);
       struct node * cur = head -> first;
       struct node * to_free = head -> first;
       while (cur -> next != start_node){
           head -> count--;
           to_free = cur;
           cur = cur -> next;
           myfree(to_free);
       }
       head -> count --;
       head -> first = cur -> next;
    }
    else{
        struct node * start = head -> first;
        struct node * cur = head -> first;
        while (cur -> next != NULL){
            cur = cur -> next;
        }
        cur -> next = start;
    }
    return head;
}


int main(int argc, char *argv[]) {
    clock_t t; 
    clock_t total;
    printf("Enter number of elements in Linked List : ");
    int n;
    scanf("%d", &n);
    //total = clock();
    t = clock(); 
    
    struct linkedList * head;
    head = createRandomizedCyclic(n);
    
    //t = clock() - t; 
    
    //double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    
    //printf("\ncreateRandomizedCyclic(n) took %f seconds to execute \n", time_taken); 
    
    //t = clock(); 

    if (detectCycle(head) == 1){
        printf("\nThere is a loop in the linked list. \n");
        // printf("Printing unique nodes : ");
        // struct node * cur = head -> first;
        // printf("[ ");
        // for (int i = 0; i < n; i++){
        //     printf( "%d ", cur -> element);
        //     cur = cur -> next;
        // }
        // printf(" ] \n");
    }
    else{
        printf("\nThere is no loop in the linked list. \n");
        // printList(head);
    }

    //t = clock() - t; 
    
    //time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    
    //printf("\ndetectCycle(head) took %f seconds to execute \n", time_taken);

    //t = clock(); 

	//printf("Converting into Circular List \n");
    head = makeCircularList(head);
    //printf("\nNo. of Elements in Linked List now are : %d \n", head -> count);

    //t = clock() - t;

    //time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 
    
    //printf("\nmakeCircularList(head) took %f seconds to execute \n", time_taken);

    // printf("Printing Elements in Cycle : ");
    // struct node * cur = head -> first;
    // printf("[ ");
    //     for (int i = 0; i < head-> count; i++){
    //         printf( "%d ", cur -> element);
    //         cur = cur -> next;
    //     }
    // printf(" ] \n");

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds 

    printf("\nValue of n is %d \n", n);
    printf("Total Heap Space used : %d \n", heapspace);
    printf("Total Running Time : %f \n", time_taken);
	return 0;
}


