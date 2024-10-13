#include <stdio.h>
#define N 5
int queue[N], front = -1, rear = -1;

void PUSH(int val)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = val;
    }
    else if ((rear + 1) % N == front)
    {
        printf("QUEUE IS FULL");
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = val;
    }
    // printf("%d ", val);
}
void POP()
{
    if (front == -1 && rear == -1)
    {
        printf("UNDERFLOW");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % N;
    }
}
void display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("EMPTY!");
    }
    else
    {
        while (i != rear)
        {
            printf("%d ", queue[i]);
            i = (i + 1) % N;
        }
        printf("%d ", queue[rear]);
    }
}
int main()
{
    int choice;
    int val;
    while (choice != 4)
    {
        printf("\nEnter 1 to PUSH:\n ");
        printf("Enter 2 to POP:\n ");
        printf("Enter 3 to DISPLAY:\n ");
        printf("Enter 4 to EXIT: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value you want to PUSH: ");
            scanf("%d", &val);
            PUSH(val);
            break;
        case 2:
            POP();
            break;
        case 3:
            display();
            break;
        }
    }
    return 0;
}