#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Deque {
    int size;
    int queue[MAX_SIZE];
    int front, rear;
};

void initializeDeque(struct Deque *deque, int size) {
    deque->size = size;
    deque->front = -1;
    deque->rear = -1;
}

int isFull(struct Deque *deque) {
    return ((deque->front == 0 && deque->rear == deque->size - 1) || (deque->rear == (deque->front - 1) % (deque->size - 1)));
}

int isEmpty(struct Deque *deque) {
    return (deque->front == -1);
}

void enqueueFront(struct Deque *deque, int item) {
    if (isFull(deque)) {
        printf("Queue is full. Cannot enqueue at the front.\n");
    } else {
        if (isEmpty(deque)) {
            deque->front = 0;
            deque->rear = 0;
        } else if (deque->front == 0) {
            deque->front = deque->size - 1;
        } else {
            deque->front = (deque->front - 1) % (deque->size - 1);
        }
        deque->queue[deque->front] = item;
    }
}

void enqueueRear(struct Deque *deque, int item) {
    if (isFull(deque)) {
        printf("Queue is full. Cannot enqueue at the rear.\n");
    } else {
        if (isEmpty(deque)) {
            deque->front = 0;
            deque->rear = 0;
        } else if (deque->rear == deque->size - 1) {
            deque->rear = 0;
        } else {
            deque->rear = (deque->rear + 1) % (deque->size - 1);
        }
        deque->queue[deque->rear] = item;
    }
}

int dequeueFront(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue is empty. Cannot dequeue from the front.\n");
        return -1;
    } else {
        int item = deque->queue[deque->front];
        if (deque->front == deque->rear) {
            deque->front = -1;
            deque->rear = -1;
        } else {
            deque->front = (deque->front + 1) % (deque->size - 1);
        }
        return item;
    }
}

int dequeueRear(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue is empty. Cannot dequeue from the rear.\n");
        return -1;
    } else {
        int item = deque->queue[deque->rear];
        if (deque->front == deque->rear) {
            deque->front = -1;
            deque->rear = -1;
        } else if (deque->rear == 0) {
            deque->rear = deque->size - 1;
        } else {
            deque->rear = (deque->rear - 1) % (deque->size - 1);
        }
        return item;
    }
}

void traverse(struct Deque *deque) {
    if (isEmpty(deque)) {
        printf("Queue is empty.\n");
    } else {
        int i = deque->front;
        printf("Deque contents: ");
        while (1) {
            printf("%d ", deque->queue[i]);
            if (i == deque->rear) {
                break;
            }
            i = (i + 1) % (deque->size - 1);
        }
        printf("\n");
    }
}

int main() {
    struct Deque deque;
    int size;

    printf("Enter the size of the deque: ");
    scanf("%d", &size);

    initializeDeque(&deque, size);

    while (1) {
        int choice, item;
        printf("\n1. Enqueue at front\n");
        printf("2. Enqueue at rear\n");
        printf("3. Dequeue from front\n");
        printf("4. Dequeue from rear\n");
        printf("5. Traverse\n");
        printf("6. Is Empty\n");
        printf("7. Is Full\n");
        printf("8. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue at the front: ");
                scanf("%d", &item);
                enqueueFront(&deque, item);
                break;
            case 2:
                printf("Enter the item to enqueue at the rear: ");
                scanf("%d", &item);
                enqueueRear(&deque, item);
                break;
            case 3:
                item = dequeueFront(&deque);
                if (item != -1) {
                    printf("Dequeued from front: %d\n", item);
                }
                break;
            case 4:
                item = dequeueRear(&deque);
                if (item != -1) {
                    printf("Dequeued from rear: %d\n", item);
                }
                break;
            case 5:
                traverse(&deque);
                break;
            case 6:
                if (isEmpty(&deque)) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue is not empty.\n");
                }
                break;
            case 7:
                if (isFull(&deque)) {
                    printf("Queue is full.\n");
                } else {
                    printf("Queue is not full.\n");
                }
                break;
            case 8:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}