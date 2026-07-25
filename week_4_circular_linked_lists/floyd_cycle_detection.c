#include "cycle_detection.h"

int detectCycle(struct linkedList * head) {
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
