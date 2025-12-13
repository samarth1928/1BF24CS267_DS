#include <stdio.h>
#include <stdlib.h>

#define SIZE 5  

int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue is FULL\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY\n");
    } else {
        printf("%d dequeued from queue\n", queue[front]);
        front++;
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY\n");
    } else {
        printf("Front element is: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is EMPTY\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
