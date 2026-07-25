#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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

struct node {
	int element;
	struct node * next;
};

struct linkedList {
	int count;
	struct node * first;
};

struct linkedList * insert(struct linkedList *head, int ele) {
    struct node *newnode = (struct node*) myalloc (sizeof(struct node));
    newnode -> next = NULL;
    newnode -> element = ele;
    if (head -> count == 0){
        head -> first = newnode;
    }
    else{
        struct node *cur;
        cur = head -> first;
        while (cur -> next != NULL){
            cur = cur -> next;
        }
        cur -> next = newnode;
    }
    head -> count++;
    return head;
}

struct linkedList * createList (int n){
    srand(time(0));
    struct linkedList * head = (struct linkedList *) myalloc (sizeof(struct linkedList));
    head -> first = NULL;
	head -> count = 0;
    for (int i = 0; i < n; i++){
        int r = rand() % 100;
        head = insert(head, r);
    }
    return head;
}

struct linkedList * createCycle(struct linkedList * head){
    srand(time(0));
    int coin = rand() % 2;
    if (coin == 0){
        return head;
    }
    else{
        int r = rand() % (head -> count - 1);
        int count = 0;
        struct node * cur = head -> first;
        while (count != r){
            count++;
            cur = cur -> next;
        }
        struct node * cycle = cur;
        cur = head -> first;
        while (cur-> next != NULL){
            cur = cur -> next;
        }
        cur -> next = cycle;
        return head;
    }
}
struct linkedList * createRandomizedCyclic(int n){
    
    struct linkedList * head = (struct linkedList *) myalloc (sizeof(struct linkedList));
	
	head -> first = NULL;
	head -> count = 0;
    
    head = createList(n);
    head = createCycle(head);

    return head;
}

int detectLoop_Tortoise_and_Hare(struct linkedList * head) {
    struct node * slow_p = head -> first;
    struct node * fast_p = head -> first;
 
    while (slow_p && fast_p && fast_p -> next) {
        slow_p = slow_p -> next;
        fast_p = fast_p -> next -> next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}

struct node * start_of_loop(struct linkedList * head){
    struct node * slow_p = head -> first;
    struct node * fast_p = head -> first;
 
    while (slow_p && fast_p && fast_p -> next) {
        slow_p = slow_p -> next;
        fast_p = fast_p -> next -> next;
        if (slow_p == fast_p) {
            break;
        }
    }
    return slow_p;
}

int detectloop_LinkReversal(struct linkedList * head){

    struct node * cur = head -> first;
    struct linkedList * head_copy = (struct linkedList *) myalloc (sizeof(struct linkedList));
    head_copy -> first = NULL;
    head_copy -> count = 0;
    for (int i = 0; i < head -> count; i++){
        head_copy = insert(head_copy, cur -> element);
        head_copy -> count++;
        cur = cur -> next;
    }
    cur = head -> first;
    struct node * prev = NULL;
    struct node * next = NULL;
    int count = 0;
    while (cur != NULL){
        //printf("%d ", cur -> next -> element);
        count++;
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
        //printf(" Cur : %d, Cur -> Next : %d, Prev : %d \n", cur -> element, cur -> next -> element, prev -> element);
    }
    

    // head -> first = prev;

    // cur = head -> first;
    // prev = NULL;
    // next = NULL;
    // while (cur != NULL){
    //         //printf("%d ", cur -> element);
    //         next = cur -> next;
    //         cur -> next = prev;
    //         prev = cur;
    //         cur = next;
    //     }
    // head -> first = prev;

    if (count != head -> count){
        head = head_copy;
        return 1;
    }
    return 0;
}

struct linkedList * makeCircularList(struct linkedList * head){
    if (detectLoop_Tortoise_and_Hare(head) == 1){
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

void printList(struct linkedList * head){
    struct node *cur;
    cur = head -> first;
	printf(" [ ");
    while (cur != NULL){
        printf("%d  ",cur -> element);
        cur = cur -> next;
    }
	printf("] \n");
}

int main(int argc, char *argv[]) {
    printf("Enter number of elements in Linked List : ");
    int n;
    scanf("%d", &n);
    struct linkedList * head;
    head = createRandomizedCyclic(n);
    if (detectLoop_Tortoise_and_Hare(head) == 1){
        printf("There is a loop in the linked list from Node with element %d ", start_of_loop(head)-> element);
        printf("Printing unique nodes : ");
        struct node * cur = head -> first;
        printf("[ ");
        for (int i = 0; i < n; i++){
            printf( "%d ", cur -> element);
            cur = cur -> next;
        }
        printf(" ] ");
    }
    else{
        printf("There is no loop in the linked list. Status of Linked List is:  ");
        printList(head);
    }
	printf("Converting into Circular List \n");
    head = makeCircularList(head);
    printf("No. of Elements in Linked List now are : %d \n", head -> count);
    printf("Printing Elements in Cycle : ");
    struct node * cur = head -> first;
    printf("[ ");
        for (int i = 0; i < head-> count; i++){
            printf( "%d ", cur -> element);
            cur = cur -> next;
        }
    printf(" ] \n");
    printf("Total Heap Space used : %d", heapspace);
	return 0;
}

