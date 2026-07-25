#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
	int element;
	struct node * next;
};

struct linkedList {
	int count;
	struct node * first;
};

void* myalloc(int x);

void myfree(void* x);

struct linkedList* createList(int N);

struct linkedList * createCycle(struct linkedList * head);

void printList(struct linkedList * head);

struct linkedList * insert(struct linkedList *head, int ele);

struct node * start_of_loop(struct linkedList * head);

struct linkedList * createRandomizedCyclic(int n);