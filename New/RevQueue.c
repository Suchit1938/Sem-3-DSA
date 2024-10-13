#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the queue

// Queue structure
typedef struct {
    int items[MAX];
    int front, rear;
} Queue;

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function to initialize a queue
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is empty
int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

// Function to check if the queue is full
int isQueueFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Function to enqueue an element
void enqueue(Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("Queue is full!\n");
    } else {
        if (q->front == -1)
            q->front = 0;  // Set front to 0 if first element is added
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an element
int dequeue(Queue *q) {
    int item;
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;  // Reset the queue
        }
        return item;
    }
}

// Function to display the queue
void displayQueue(Queue *q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Stack functions
void initStack(Stack *s) {
    s->top = -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isStackFull(s)) {
        printf("Stack is full!\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty!\n");
        exit(1);
    } else {
        return s->items[s->top--];
    }
}

// Function to reverse the queue
void reverseQueue(Queue *q) {
    Stack s;
    initStack(&s);

    // Dequeue all elements from the queue and push them onto the stack
    while (!isQueueEmpty(q)) {
        push(&s, dequeue(q));
    }

    // Pop all elements from the stack and enqueue them back into the queue
    while (!isStackEmpty(&s)) {
        enqueue(q, pop(&s));
    }
}

// Main function
int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Original Queue:\n");
    displayQueue(&q);

    // Reverse the queue
    reverseQueue(&q);

    printf("Reversed Queue:\n");
    displayQueue(&q);

    return 0;
}