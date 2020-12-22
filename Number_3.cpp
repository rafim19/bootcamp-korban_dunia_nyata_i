#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <math.h>
// #include <unistd.h>
// #include <conio.h>

struct node {
    int dt;
    struct node* next;
};

void printMiddle(struct node* head);
void push(struct node** head_ref, int new_data);
void printList(struct node* ptr);

int main() { 
    struct node* head = NULL; 
    int i; 

    for (i = 5; i > 0; i--) { 
        push(&head, i); 
        printList(head); 
        printMiddle(head); 
    } 

    return 0; 
}

void printMiddle(struct node* head) { 
    int count = 0; 
    struct node* mid = head; 

    while (head != NULL) { 
        if (count & 1) 
            mid = mid->next; 
  
        ++count; 
        head = head->next; 
    } 

    if (mid != NULL) 
        printf("The middle element is [%d]\n\n", mid->dt); 
} 

void push(struct node** head_ref, int new_data) { 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 

    new_node->dt = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
}

void printList(struct node* ptr) { 
    while (ptr != NULL) { 
        printf("%d->", ptr->dt); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); 
} 