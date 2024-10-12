#include <stdio.h>
#define MAX 10
int Que[MAX];
int front = -1, rear = -1;

void push()
{
    int value;
    printf("Enter the value to insert in Queue : ");
    scanf("%d", &value);
    if (front == 0 && rear == MAX - 1)
    {
        printf("Overflow condition ");
    }
    else if (front == -1 && rear == -1)
    {
        front = 0, rear = 0;
        Que[rear] = value;
    }
    else if (front != 0 && rear == MAX - 1)
    {
        rear = 0;
        Que[rear] = value;
    }
    else
    {
        Que[++rear] = value;
    }
}

int pop()
{
    int dvalue;
    if (front == -1 && rear == -1)
    {
        printf("Underflow condition");
        return -1;
    }
    if (front == rear)
    {
        front = rear = -1;
        dvalue = Que[front];
    }
    if (front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return dvalue;
}

int peek()
{
    if (front == -1 && rear == -1)
    {
        printf("The underflow condition");
        return -1;
    }
    else
    {
        return Que[front];
    }
}

int display()
{
    if (front == -1, rear == -1)
    {
        printf("Queue Underflow condition ");
    }
    else
    {
        if (front < rear)
        {
            for (int i = 0; i < rear; i++)
                printf("%d \t", Que[i]);
        }
        else
        {
            for (int i = front; i < MAX; i++)
                printf("%d\t", Que[i]);
            for (int i = 0; i < rear; i++)
                printf("%d\t", Que[i]);
        }
    }
}
int main()
{

    return 0;
}