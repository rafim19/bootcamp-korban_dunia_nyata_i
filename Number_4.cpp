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

void removeDuplicates(struct Node* head);
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node);

int main() { 
    struct Node* head = NULL; 

    push(&head, 20); 
    push(&head, 13); 
    push(&head, 13);   
    push(&head, 11); 
    push(&head, 11); 
    push(&head, 11);                                     
  
    printf("\n Linked list before duplicate removal  "); 
    printList(head);  

    removeDuplicates(head);  
  
    printf("\n Linked list after duplicate removal ");          
    printList(head);             
    
    return 0; 
}

void removeDuplicates(struct Node* head) { 
    struct Node* current = head; 

    struct Node* next_next;

    if (current == NULL) { 
       return;  
    }

    while (current->next != NULL) {
       if (current->dt == current->next->dt) {             
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } else { 
          current = current->next;  
       } 
    }
}

void push(struct Node** head_ref, int new_data) { 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

    new_node->dt  = new_data; 
    new_node->next = (*head_ref);
    (*head_ref)    = new_node; 
} 

void printList(struct Node *node) { 
    while (node != NULL) { 
       printf("%d ", node->dt); 
       node = node->next; 
    }
}