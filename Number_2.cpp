#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <math.h>
// #include <unistd.h>
// #include <conio.h>

int detectLoop(struct Node* list);
void push(struct Node** head1, int newdt);

struct Node {
    int dt;
    struct Node* next;
};
 
int main() {
    struct Node* head = NULL;
 
    push(&head, 5);
    push(&head, 17);
    push(&head, 13);
    push(&head, 20);

    head->next->next->next->next = head;
 
    if (detectLoop(head)) {
        printf("Loop found");
    } else {
        printf("No Loop");
    }

    return 0;
}

int detectLoop(struct Node* list) {
    struct Node *sp = list, *fp = list;
 
    while (sp && fp && fp->next) {
        sp = sp->next;
        fp = fp->next->next;
        if (sp == fp) {
            return 1;
        }
    }
    return 0;
}

void push(struct Node** head1, int newdt) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
 
    new_node->dt = newdt;
    new_node->next = (*head1);
    (*head1) = new_node;
}