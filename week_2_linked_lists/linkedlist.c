#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void insertFirst(struct linkedList *head, int ele) {
    struct node* cur = (struct node*) malloc (sizeof(struct node));
    cur = head -> first;
    struct node* newhead = (struct node*) malloc (sizeof(struct node));
    newhead -> element = ele;
    newhead -> next = cur;
    head -> count++;
    head -> first = newhead;
}

/* inserts a given element at the beginning of the list */
struct node * deleteFirst(struct linkedList * head) {
    struct node* cur = (struct node*) malloc (sizeof(struct node));
    cur = head -> first -> next;
    struct node* deleted = (struct node*) malloc (sizeof(struct node));
    deleted = head -> first;
    deleted -> next = NULL;
    head -> first = cur;
    head -> count--;
    return deleted;
}
/* deletes the first element of the list and returns pointer to the deleted
node. */
void printList(struct linkedList * head) {
    struct node* cur = (struct node*) malloc (sizeof(struct node));
    cur = head -> first;
    while (cur -> next != NULL) {
        printf("%d  ", cur -> element);
        cur = cur -> next;
    }
    printf("\n");
}
/* prints all the elements in the list */
int search(struct linkedList * head, int ele) {
    struct node* cur = (struct node*) malloc (sizeof(struct node));
    cur = head -> first;
    while (cur -> next != NULL) {
        if (cur -> element == ele) {
            return 1;
        }
        cur = cur -> next;
    }
    return 0;
}
/* searches for a given element in the linked list. Returns 1 if found, 0
otherwise. */
struct node * delete(struct linkedList * head, int ele) {
    struct node* cur = (struct node*) malloc (sizeof(struct node));
    cur = head -> first;
    struct node* ahead = (struct node*) malloc (sizeof(struct node));
    ahead = head -> first -> next;
    if (cur -> element == ele) {
        deleteFirst(head);
    }
    // if (ahead -> element = ele){
    //     cur -> next = ahead -> next;
    //     ahead -> next = NULL;
    //     return ahead;
    // }
    while (ahead -> next != NULL) {
        if (ahead -> element == ele) {
            cur -> next = ahead -> next;
            ahead -> next = NULL;
            return ahead;
        }
        ahead = ahead -> next;
        cur = cur -> next;
    }
    printf("Element was not found. ");
    return head -> first;
}