#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void createList(int n) {
    int data;
    struct node *newNode, *temp;

    if (n <= 0) {
        printf("Invalid size.\n");
        return;
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);

    newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;
    head = newNode;
    temp = head;

    for (int i = 2; i <= n; i++) {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);

        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }

    printf("Linked list created successfully.\n");
}

void deleteAtBegin() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    head = head->next;
    free(temp);

    printf("Node deleted from beginning.\n");
}


void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct node *temp = head;
    struct node *q = NULL;

    while (temp->next != NULL) {
        q = temp;
        temp = temp->next;
    }

    q->next = NULL;
    free(temp);

    printf("Node deleted from end.\n");
}

void deleteByValue(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    struct node *q = NULL;

    if (head->data == value) {
        deleteAtBegin();
        return;
    }

    while (temp != NULL && temp->data != value) {
        q = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in list.\n", value);
        return;
    }

    q->next = temp->next;
    free(temp);

    printf("Node with value %d deleted.\n", value);
}

void displayList() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main() {
    int choice, n, value;

    printf("\n--- Singly Linked List (Deletion Operations) ---\n");
    printf("1. Create a list\n");
    printf("2. Delete from Beginning\n");
    printf("3. Delete from End\n");
    printf("4. Delete by Value\n");
    printf("5. Display List\n");
    printf("6. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                deleteAtBegin();
                break;

            case 3:
                deleteAtEnd();
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;

            case 5:
                displayList();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

