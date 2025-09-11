// Circular Implementation of Queue
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    int items[SIZE];
    int front, rear;
} Queue, * QPtr;

void initQueue(QPtr q);
int isEmpty(QPtr q);
int isFull(QPtr q);
void enqueue(QPtr q, int value);
int dequeue(QPtr q);
int peek(QPtr q);
void display(QPtr q);

int main(void) {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    dequeue(&q);
    display(&q);

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // Should fail
    display(&q);

    printf("Front element: %d\n", peek(&q));
    return 0;
}

// Initialize queue
void initQueue(QPtr q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(QPtr q) {
    return (q->front == -1);
}

// Check if queue is full
int isFull(QPtr q) {
    return ((q->rear + 1) % SIZE == q->front);
}

// Insert element
void enqueue(QPtr q, int value) {
    int success = 1;

    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d\n", value);
        success = 0;
    }
    else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % SIZE;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }

    return;
}

// Remove element
int dequeue(QPtr q) {
    int value = -1;

    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
    }
    else {
        value = q->items[q->front];
        if (q->front == q->rear) {
            q->front = q->rear = -1; // queue becomes empty
        }
        else {
            q->front = (q->front + 1) % SIZE;
        }
        printf("Dequeued: %d\n", value);
    }

    return value;
}

// Peek front element
int peek(QPtr q) {
    int value = -1;

    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    }
    else {
        value = q->items[q->front];
    }

    return value;
}

// Display queue contents
void display(QPtr q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    }
    else {
        printf("Queue: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->items[i]);
            if (i == q->rear) break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}