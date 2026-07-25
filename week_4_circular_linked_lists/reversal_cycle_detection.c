#include "cycle_detection.h"

int detectCycle(struct linkedList * head){

    struct node * cur = head -> first;
    struct node * prev = NULL;
    struct node * next = NULL;
    int count = 0;
    
    while (cur != NULL){
        count++;
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    
    head -> first = prev;

    cur = head -> first;
    prev = NULL;
    next = NULL;
    while (cur != NULL){
            next = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = next;
        }
    head -> first = prev;

    if (count != head -> count){
        return 1;
    }
    return 0;
}