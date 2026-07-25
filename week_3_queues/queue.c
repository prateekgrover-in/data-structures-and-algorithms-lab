#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

Queue newQ(){
    struct queue new_q;
    new_q.first = NULL;
    new_q.last = NULL;
    new_q.size = 0;
    return new_q;
}

bool isEmptyQ(Queue q){
    if (q.size == 0){
        return true;
    }
    else{
        return false;
    }
}

Queue delQ(Queue q){
    if (q.size == 0){
        return q;
    }
    else if (q.size == 1){
        q.first = NULL;
        q.last = NULL;
    }
    else{
        struct node* to_delete = q.first;
        struct node* new_first = q.first -> next;
        q.first = new_first;
        free(to_delete);
    }
    q.size--;
    return q;
}

void * front(Queue q){
    if (q.size == 0){
        return NULL;
    }
    else{
        return q.first -> data_ptr;
    }
}

Queue addQ(Queue q, void * e){
    struct node* new_element = (struct node*) malloc (sizeof(struct node));
    new_element -> next = NULL;
    new_element -> data_ptr = e;
    if (q.size == 0){
        q.first = new_element;
        q.last = new_element;
        q.size = 1;
    }
    else{
        q.last -> next = new_element;
        q.last = new_element;
        q.size++;
    }
    //q.size++;
    return q;
}

int lengthQ(Queue q){
    return q.size;
}

void printQ(Queue q) {
    struct node * cur = q.first;
    while (cur -> next != NULL){
        printf("%s, ", cur -> data_ptr);
        cur = cur -> next;
    }
    printf("%s", cur -> data_ptr);
}