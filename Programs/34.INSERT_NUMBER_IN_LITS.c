#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a number at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    // Assign data to the new node
    newNode->data = data;

    // Set the next pointer of the new node to the current head
    newNode->next = head;

    // Update the head to point to the new node
    head = newNode;

    return head;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty linked list

    int num;
    char choice;

    // Insert numbers into the list based on user input
    do {
        printf("Enter a number to insert: ");
        scanf("%d", &num);
        head = insertAtBeginning(head, num);

        printf("Do you want to insert another number? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    // Print the list
    printf("List after insertion: ");
    printList(head);

    return 0;
}

