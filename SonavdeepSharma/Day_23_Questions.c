#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

// 1. Find the kth node from the end
int findKthFromEnd(struct Node* head, int k) {
    int count = 0;
    struct Node* temp = head;

    // First, count the total number of nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    // If k is greater than the number of nodes
    if (k > count)
        return -1;

    // Move to (count - k)th node from the start
    temp = head;
    for (int i = 0; i < count - k; i++) {
        temp = temp->next;
    }

    return temp->data;
}

// 2. Remove duplicates from a sorted linked list
void removeDuplicates(struct Node* head) {
    struct Node* temp = head;

    while (temp != NULL && temp->next != NULL) {
        if (temp->data == temp->next->data) {
            struct Node* duplicate = temp->next;
            temp->next = temp->next->next;
            free(duplicate);
        } 
        else 
        {
            temp = temp->next;
        }
    }
}

// 3. Delete the middle node of the list
void deleteMiddle(struct Node** head)
{
    if (*head == NULL || (*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node* slow = *head;
    struct Node* fast = *head;
    struct Node* prev = NULL;

    while (fast != NULL && fast->next != NULL)
      {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // 'slow' is the middle node
    prev->next = slow->next;
    free(slow);
}


// Main function to demonstrate all problems

int main() 
{
    struct Node* head = NULL;

   
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Original List:\n");
    printList(head);

    // Problem 1: Find kth node from end
    int k = 2;
    int result = findKthFromEnd(head, k);
    printf("\n%dth node from end is: %d\n", k, result);

    // Problem 2: Remove duplicates
    struct Node* dupList = NULL;
    append(&dupList, 2);
    append(&dupList, 2);
    append(&dupList, 4);
    append(&dupList, 4);
    append(&dupList, 5);

    printf("\nList with duplicates:\n");
    printList(dupList);

    removeDuplicates(dupList);
    printf("After removing duplicates:\n");
    printList(dupList);

    // Problem 3: Delete the middle node
    printf("\nDeleting middle node from original list:\n");
    printList(head);

    deleteMiddle(&head);
    printf("After deleting middle node:\n");
    printList(head);

    return 0;
}
