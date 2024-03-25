#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node * next;

};

bool hasCycle(struct node *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct node *slow = head;
    struct node *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}

int main()
{
    struct node * head;
    head = malloc(sizeof(struct node));
    head-> data = 23;
    head-> next = NULL;

    struct node *current = malloc(sizeof(struct node));
    head -> next = current;
    current->data = 28;
    current-> next = head;


    bool cycleExists = hasCycle(head);

    if (cycleExists) {
        printf("The linked list has a cycle.\n");
    } else {
        printf("The linked list does not have a cycle.\n");
    }


    return 0;
}
