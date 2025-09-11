#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct {
    int items[SIZE];
    int top;
} Stack, * SPtr;

void initStack(SPtr s);
int isEmpty(SPtr s);
int isFull(SPtr s);
void push(SPtr s, int value);
int pop(SPtr s);
int peek(SPtr s);
void display(SPtr s);

int main(void) {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    pop(&s);
    display(&s);

    push(&s, 40);
    push(&s, 50);
    push(&s, 60); // Should fail (stack is full)
    display(&s);

    printf("Top element: %d\n", peek(&s));
    return 0;
}

// Initialize stack
void initStack(SPtr s) {
    s->top = -1;
}

// Check if empty
int isEmpty(SPtr s) {
    int result = 0;
    if (s->top == -1) {
        result = 1;
    }
    return result;
}

// Check if full
int isFull(SPtr s) {
    int result = 0;
    if (s->top == SIZE - 1) {
        result = 1;
    }
    return result;
}

// Push operation
void push(SPtr s, int value) {
    int success = 1;

    if (isFull(s)) {
        printf("Stack is full! Cannot push %d\n", value);
        success = 0;
    }
    else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed: %d\n", value);
    }

    return;
}

// Pop operation
int pop(SPtr s) {
    int value = -1;

    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop.\n");
    }
    else {
        value = s->items[s->top];
        s->top--;
        printf("Popped: %d\n", value);
    }

    return value;
}

// Peek at top element
int peek(SPtr s) {
    int value = -1;

    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    }
    else {
        value = s->items[s->top];
    }

    return value;
}

// Display stack
void display(SPtr s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
    }
    else {
        printf("Stack (top to bottom): ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}