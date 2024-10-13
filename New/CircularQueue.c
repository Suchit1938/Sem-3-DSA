#include <stdio.h>
#define MAX 5  // Maximum size of the circular queue

int circularQueue[MAX];
int front = -1, rear = -1;

// Function to check if the circular queue is full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Function to check if the circular queue is empty
int isEmpty() {
    return front == -1;
}

// Function to enqueue an element into the circular queue
void enqueue(int value) {
    if (isFull()) {
        printf("Circular queue is full. Cannot enqueue %d\n", value);
    } else {
        if (front == -1) {
            front = 0;  // First element
        }
        rear = (rear + 1) % MAX;
        circularQueue[rear] = value;
        printf("Enqueued %d\n", value);
    }
}

// Function to dequeue an element from the circular queue
void dequeue() {
    if (isEmpty()) {
        printf("Circular queue is empty. Cannot dequeue\n");
    } else {
        printf("Dequeued %d\n", circularQueue[front]);
        if (front == rear) {
            // Only one element left, so reset the queue
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

// Function to display the circular queue
void displayCircularQueue() {
    if (isEmpty()) {
        printf("Circular queue is empty.\n");
    } else {
        printf("Circular queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", circularQueue[i]);
            i = (i + 1) % MAX;
        }
        printf("%d\n", circularQueue[rear]);
    }
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    displayCircularQueue();
    dequeue();
    displayCircularQueue();
    enqueue(40);
    enqueue(50);
    enqueue(60);
    displayCircularQueue();
    return 0;
}