#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    // Allocate memory for new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Assign data to the new node
    new_node->data = new_data;
    // Set the next of the new node as the current head
    new_node->next = *head_ref;
    // Move the head to point to the new node
    *head_ref = new_node;
}

// Function to delete a node with a given key from the linked list
void deleteNode(struct Node** head_ref, int key) {
    // Store head node
    struct Node* temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp);             // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL)
        return;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    free(temp);
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main method
int main() {
    // Initialize empty linked list
    struct Node* head = NULL;

    // Insert elements into the linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);

    printf("Linked list after insertion: ");
    printList(head);

    // Delete an element from the linked list
    deleteNode(&head, 2);

    printf("Linked list after deletion: ");
    printList(head);

    return 0;
}
