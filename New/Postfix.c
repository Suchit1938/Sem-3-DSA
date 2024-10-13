#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push element onto the stack
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

// Pop element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Function to evaluate a postfix expression
int evaluatePostfix(char postfix[]) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            // If the character is an operand, push it to the stack
            push(ch - '0');  // Convert char to int
        } else {
            // If the character is an operator, pop two operands from the stack and apply the operator
            int operand2 = pop();
            int operand1 = pop();
            int result;

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = operand1 ^ operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            // Push the result back onto the stack
            push(result);
        }
    }

    // The final result is the only element left in the stack
    return pop();
}

// Main function
int main() {
    char postfix[MAX];

    printf("Enter a postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);

    printf("Result of postfix evaluation: %d\n", result);

    return 0;
}