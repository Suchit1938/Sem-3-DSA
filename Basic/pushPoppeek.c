#include <stdio.h>
#define SIZE 6
int st[SIZE], top = -1;

void push(int st[], int value)
{
    if (top == SIZE - 1)
    {
        printf("The stack is full \n");
    }
    else
    {
        top++;
        st[top] = value;
    }
}

int pop(int st[])
{
    int value;
    if (top == -1)
    {
        printf("The stack is already empty \n");
        return -1;
    }
    else
    {
        value = st[top];
        top--;
        return value;
    }
}

void display(int st[])
{
    if (top == -1)
    {
        printf("Stack underflow \n");
    }
    else
    {
        for (int i = top; i >= 0; i--)
            printf("\n %d", st[i]);
        printf("\n");
    }
}

int peek(int st[])
{
    if (top == -1)
    {
        printf("The underflow condition \n");
    }
    else
    {
        return st[top];
    }
}
int main()
{
    int value, option;

    do
    {
        printf("1. push an element in stack \n");
        printf("2. pop an element in stack \n");    
        printf("3. peek an element in stack \n");
        printf("4. diplay an element in stack \n");
        printf("5. Exit \n");
        printf("Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("enter a number to add to satck \n");
            scanf("%d", value);
            push(st, value);
            break;

        case 2:
            value = pop(st);
            if(value != -1)
            printf("The value of top %d is deleted ", value);
            break;

        case 3:
            value = peek(st);
            if(value != -1)
            printf("The topmost value in stack is %d", value);
            break;

        case 4:
            display(st);
            break;
        }

    } while (option != 5);

    return 0;
}