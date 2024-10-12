#include <stdio.h>
#define max 21
int st[max];
int top = -1;
void push(int ele)
{
    if (top == max - 1)
    {
        printf("Overflow condition");
    }
    else
    {
        top++;
        st[top] = ele;
    }
}
int pop()
{
    int dvalue;
    if (top == -1)
    {
        printf("Underflow condition");
        return -1;
    }
    else
    {
        dvalue = st[top];
        top--;
    }
    return dvalue;
}
int main()
{
    int Nele;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
        push(arr[i]);
    for (int i = 0; i < 10; i++)
        printf("arr[%d] : %d \n", i, arr[i]);
    printf("\n\n");
    for (int i = 0; i < 10; i++)
    {
        Nele = pop();
        arr[i] = Nele;
    }
    for (int i = 0; i < 10; i++)
        printf("arr[%d] : %d \n", i, arr[i]);

    return 0;
}