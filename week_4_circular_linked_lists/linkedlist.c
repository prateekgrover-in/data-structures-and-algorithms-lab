#include "linkedlist.h"

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


struct linkedList * createRandomizedCyclic(int n){
    
    struct linkedList * head = (struct linkedList *) myalloc (sizeof(struct linkedList));
	
	head -> first = NULL;
	head -> count = 0;
    
    head = createList(n);
    head = createCycle(head);

    return head;
}
