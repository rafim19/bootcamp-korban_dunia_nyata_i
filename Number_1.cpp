#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h> 
// #include <math.h>
// #include <unistd.h>
// #include <conio.h>
  
struct Node { 
    int data; 
    struct Node* next; 
}; 

void MoveNode(struct Node** dest, struct Node** source);
struct Node* SortedMerge(struct Node* a, struct Node* b);
void push(struct Node** head_ref, int new_data);
void printList(struct Node *node);

int main() { 
    struct Node* res = NULL; 
    struct Node* a = NULL; 
    struct Node* b = NULL; 

    push(&a, 50); 
    push(&a, 25); 
    push(&a, 7); 
  
    push(&b, 39); 
    push(&b, 23); 
    push(&b, 5); 

    res = SortedMerge(a, b); 
  
    printf("The Merged Linked List is: \n"); 
    printList(res); 
  
    return 0; 
} 

void MoveNode(struct Node** dest, struct Node** source) { 
    struct Node* newNode = *source; 
    assert(newNode != NULL); 

    *source = newNode->next; 
    newNode->next = *dest; 
    *dest = newNode; 
} 

struct Node* SortedMerge(struct Node* a, struct Node* b) { 
    struct Node temp; 

    struct Node* tail = &temp; 

    temp.next = NULL; 
    while (1) { 
        if (a == NULL) { 
            tail->next = b; 
            break; 
        } 
        else if (b == NULL) { 
            tail->next = a; 
            break; 
        } 
        if (a->data <= b->data) {
            MoveNode(&(tail->next), &a); 
		} else {
            MoveNode(&(tail->next), &b); 
		}
  
        tail = tail->next; 
    }
    return(temp.next); 
} 

void push(struct Node** head_ref, int new_data) { 
    struct Node* new_node = 
        (struct Node*) malloc(sizeof(struct Node)); 

    new_node->data  = new_data; 

    new_node->next = (*head_ref); 

    (*head_ref)    = new_node; 
} 

void printList(struct Node *node) { 
    while (node!=NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
