/* driver.c */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    // Create a file pointer and open the file read as command line argument.
    FILE * fileptr = fopen("example.txt", "r");
    // Declare a pointer to a linked list (head) and allocate memory to it.
    struct linkedList * head = (struct linkedList * ) malloc(sizeof(struct linkedList));
    // In a loop read the file and insert elements into the linkedList.

    
    int temp = 0;
    for (int i = 0; i < 8; i++) {
        // read the next element and store into the temp variable.
        fscanf(fileptr, "%d ", & temp);
        printf("%d ", head -> first -> element);
        // insert temp into the linked list.
        insertFirst(head, temp);
    }
    // // close the file pointer
    fclose(fileptr);
    // printList(head);
    // deleteFirst(head);
    // printList(head);

    FILE * fptr;
    fptr = fopen("result.txt", "w");
    struct node* iterator = head -> first;

    if (fptr == NULL) {
        printf("Error\n");
    }

    else {
        while (iterator != NULL) {
            fprintf(fptr, "%d ", iterator -> element);
            iterator = iterator -> next;
        }
    }

    fclose(fptr);
}