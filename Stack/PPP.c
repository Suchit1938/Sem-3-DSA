#include<stdio.h>
#define size 30
int st[size];
int top = -1;
void push()
{
    int value;
    printf("Enter the value to insert at top of stack : ");
    scanf("%d", &value);
    if(top == size - 1)
    {
        printf("The stack is full or overflow condition");
    }
    else{
        top++;
        st[top] = value;
    }
}

int pop()
{
    int dvalue;
    if(top == -1)
    {
        printf("The underflow condition");
        return -1;
    }
    else{
        dvalue = st[top];
        top--;
    }
    return dvalue;
}

int peek()
{
    if(top == -1)
    {
        printf("the stack is empty");
        return -1;
    }
    return st[top];
}

void display()
{
    for (int i = top; i >= 0; i--)
    {
        printf("%d\t", st[i]);
    }
}
int main()
{
    push();
    push();
    push();
    int value = peek();
    printf("%d\t",value);
    pop();
    pop();
    peek();
    printf("%d\t",value);
    return 0;
}