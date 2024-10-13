#include <stdio.h>
#define MAX 5  // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function to check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack is full. Cannot push %d\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack\n", value);
    }
}

// Function to pop an element from the stack
void pop() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot pop\n");
    } else {
        printf("Popped %d from the stack\n", stack[top]);
        top--;
    }
}

// Function to display the stack
void displayStack() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    push(10);
    push(20);
    push(30);
    displayStack();
    pop();
    displayStack();
    return 0;
}