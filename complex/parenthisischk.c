#include <stdio.h>
// #include<conio.h>
#include <string.h>
#define Max 10
int top = -1;
int stk[Max];


void push(int stack[], char c)
{
    if (top == (Max - 1))
    {
        printf("OVERFLOW");
    }
    else
    {
        stack[++top] = c;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("UNDERFLOW");
    }
    else
    {
        return (stk[top--]);
    }
}
int main()
{
    int flag = 1;
    char expression[Max], temp;
    printf("Type an expression: ");
    gets(expression);
    for (int i = 0; i < strlen(expression); i++)
    {
        if (expression[i] == '(')
        {
            push(stk, expression[i]);
        }
        if (expression[i] == ')')
        {
            if (top == -1)
            {
                flag = 0;
            }
            else
            {
                temp = pop();
                if (expression[i] == ')' && (temp == '{' || temp == '['))
                {
                    flag = 0;
                }
            }
        }
    }
    if(top>-1)
    flag = 0;
    if(flag == 1){
        printf("\nvalid");
    }
    else{
        printf("not valid");
    }
}