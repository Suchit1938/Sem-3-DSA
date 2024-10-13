#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push element onto the stack
void push(char ch) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = ch;
    }
}

// Pop element from the stack
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Peek the top element of the stack
char peek() {
    return stack[top];
}

// Function to check precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '^') {
        return 3;
    } else {
        return 0;
    }
}

// Function to check if the character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isalnum(ch)) {
            // If the character is an operand, add it to the postfix expression
            postfix[j++] = ch;
        } else if (ch == '(') {
            // If the character is '(', push it to the stack
            push(ch);
        } else if (ch == ')') {
            // If the character is ')', pop and output from the stack until '(' is encountered
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            pop();  // Pop '(' from the stack
        } else if (isOperator(ch)) {
            // If the character is an operator
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop all the remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';  // Null terminate the postfix expression
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}