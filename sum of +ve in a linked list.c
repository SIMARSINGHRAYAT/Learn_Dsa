#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure definition
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* create(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory Allocation failed.\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert at end of list
void insert(struct node** head, int data) {
    struct node* newnode = create(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Value %d inserted successfully!\n", data);
}

// Function to count positive integers
void countPositive(struct node* head) {
    int count = 0;
    struct node* current = head;
    
    while (current != NULL) {
        if (current->data > 0) {
            count++;
        }
        current = current->next;
    }
    printf("Number of positive integers: %d\n", count);
}

// Function to display the list
void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct node* temp = head;
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to count total nodes
int countNodes(struct node* head) {
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to free the list
void freeList(struct node** head) {
    struct node* current = *head;
    struct node* next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
    printf("List cleared successfully!\n");
}

int main() {
    struct node* head = NULL;
    int choice, value;
    
    while (1) {
        printf("\n=== Linked List Operations ===\n");
        printf("1. Insert a value\n");
        printf("2. Count positive integers\n");
        printf("3. Display list\n");
        printf("4. Count total nodes\n");
        printf("5. Clear list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(&head, value);
                break;
                
            case 2:
                countPositive(head);
                break;
                
            case 3:
                display(head);
                break;
                
            case 4:
                printf("Total number of nodes: %d\n", countNodes(head));
                break;
                
            case 5:
                freeList(&head);
                break;
                
            case 6:
                printf("Exiting program...\n");
                freeList(&head);  // Clean up before exiting
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}