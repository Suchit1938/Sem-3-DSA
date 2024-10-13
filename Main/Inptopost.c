#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char st[MAX];
int top = -1;

void reverse(char str[], char temp[]);
void push(char st[], char val);
char pop(char st[]);
void InfixtoPostfix(char source[], char target[]);
int getPriority(char op);

char infix[100], postfix[100], temp[100];

int main()
{
    printf("\nEnter any infix expression: ");
    gets(infix);
    reverse(infix, temp);
    strcpy(postfix, "");
    InfixtoPostfix(temp, postfix);
    printf("\nThe corresponding postfix expression is: ");
    puts(postfix);
    strcpy(temp, "");
    reverse(postfix, temp);
    printf("\nThe prefix expression is: \n");
    puts(temp);
    return 0;
}

void reverse(char str[], char temp[])
{
    int len = strlen(str);
    int i = 0, j = len - 1;
    while (j >= 0)
    {
        if (str[j] == '(')
            temp[i] = ')';
        else if (str[j] == ')')
            temp[i] = '(';
        else
            temp[i] = str[j];
        i++;
        j--;
    }
    temp[i] = '\0';
}

void InfixtoPostfix(char source[], char target[])
{
    int i = 0, j = 0;
    char temp;
    strcpy(target, "");
    while (source[i] != '\0')
    {
        if (source[i] == '(')
        {
            push(st, source[i]);
            i++;
        }
        else if (source[i] == ')')
        {
            while ((top != -1) && (st[top] != '('))
            {
                target[j] = pop(st);
                j++;
            }
            if (top == -1)
            {
                printf("\nINCORRECT EXPRESSION");
                exit(1);
            }
            temp = pop(st); // remove left parentheses
            i++;
        }
        else if (isdigit(source[i]) || isalpha(source[i]))
        {
            target[j] = source[i];
            j++;
            i++;
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                 source[i] == '/' || source[i] == '%')
        {
            while ((top != -1) && (st[top] != '(') &&
                   (getPriority(st[top]) > getPriority(source[i])))
            {
                target[j] = pop(st);
                j++;
            }
            push(st, source[i]);
            i++;
        }
        else
        {
            printf("\nINCORRECT ELEMENT IN EXPRESSION");
            exit(1);
        }
    }
    while ((top != -1) && (st[top] != '('))
    {
        target[j] = pop(st);
        j++;
    }
    target[j] = '\0';
}

int getPriority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    else
        return -1; // To handle invalid operators
}

void push(char st[], char val)
{
    if (top == MAX - 1)
        printf("\nSTACK OVERFLOW");
    else
    {
        top++;
        st[top] = val;
    }
}

char pop(char st[])
{
    char val = ' ';
    if (top == -1)
        printf("\nSTACK UNDERFLOW");
    else
    {
        val = st[top];
        top--;
    }
    return val;
}