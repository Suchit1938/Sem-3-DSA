#include <stdio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;

void insert()
{
    int num;
    printf("Enter a number to insert in queue from rear : ");
    scanf("%d", &num);
    if (rear == MAX - 1)
    {
        printf("Overflow condtion");
    }
    else if (rear == -1 && front == -1)
    {
        rear = 0, front = 0;
        queue[rear] = num;
    }
    else
    {
        rear++;
        queue[rear] = num;
    }
}

int deletion()
{
    int val;
    if(front == -1 || front > rear)
    {
        printf("The queue is empty");
        return -1;
    }
    else{
        val = queue[rear];
        front++;
        if(front > rear)
        {
            front = rear = -1;
            return val; 
        }
    }
}
int main()
{

    return 0;
}