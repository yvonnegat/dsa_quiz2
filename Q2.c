#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int findCycleIndex(struct node *head) {
    struct node *slow = head;
    struct node *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            struct node *ptr1 = head;
            struct node *ptr2 = slow;

            int index = 0;
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
                index++;
            }
            return index;
        }
    }

    return -1;
}

int main() {
    struct node *head = malloc(sizeof(struct node));
    head->data = 23;

    struct node *current = malloc(sizeof(struct node));
    current->data = 28;

    head->next = current;
    current->next = head; // Cycle

    int cycleIndex = findCycleIndex(head);

    if (cycleIndex != -1) {
        printf("The linked list has a cycle starting at index %d.\n", cycleIndex);
    } else {
        printf("The linked list does not have a cycle.\n");
    }



    return 0;
}

