#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <math.h>
// #include <unistd.h>
// #include <conio.h>

struct Node {
    int dt;
    struct Node* next;
};

static void reverse(struct Node** head1);
void push(struct Node** head1, int newd);
void printList(struct Node* head);

int main() {
    struct Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);
 
    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed Linked list \n");
    printList(head);
    getchar();
}

static void reverse(struct Node** head1) {
    struct Node* prev = NULL;
    struct Node* current = *head1;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;

        current->next = prev;
        prev = current;
        current = next;
    }
    *head1 = prev;
}

void push(struct Node** head1, int newd) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->dt = newd;
    new_node->next = (*head1);
    (*head1) = new_node;
}

void printList(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d  ", temp->dt);
        temp = temp->next;
    }
}