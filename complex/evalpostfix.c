#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 10

char Exp[MAX];
int stk[MAX];
int top = -1;
int val;

void push(int c) {
    if (top == (MAX - 1)) {
        printf("OVERFLOW\n");
    } else {
        stk[++top] = c;
    }
}

int pop() {
    if (top == -1) {
        printf("UNDERFLOW\n");
        return -1;
    } else {
        return stk[top--];
    }
}

int main() {
    printf("Enter the postfix Expr to calc: ");
    gets(Exp);

    for (int i = 0; i < strlen(Exp); i++) {
        if (isdigit(Exp[i])) {
            push(Exp[i] - '0');
        } else {
            int op2 = pop();
            int op1 = pop();

            switch (Exp[i]) {
                case '+':
                    val = op1 + op2;
                    break;
                case '-':
                    val = op1 - op2;
                    break;
                case '*':
                    val = op1 * op2;
                    break;
                case '/':
                    val = op1 / op2;
                    break;
                case '%':
                    val = op1 % op2;
                    break;
                default:
                    printf("Invalid operator: %c\n", Exp[i]);
                    return -1;
            }
            push(val);
        }
    }
    printf("%d\n", pop());
    return 0;
}
