#include <stdio.h>
#include <string.h>
#define N 15
int st[N], top = -1;
void push(int st[], int value)
{
    if (top == N - 1){
        printf("Stack overflow");
    }
    else{
        top++;
        st[top] = value;
    }
}
int pop()
{
    int flag = 1;
    if (top == -1)
    {
        flag = 0;
        // printf("The entered string is invalid");
    }
    else
    {
        top--;
    }
    return flag;
}
int main()
{
    int n;
    printf("Enter the size of string : ");
    scanf("%d", &n);
    char arr[n];
    scanf("%s", arr);
    // int st[10];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'S')
        {
            push(st, i);
        }
        else if (arr[i] == 'X')
        {
            int check = pop();
            if(check == 0)
            {
                printf("Invalid String");
                break;
            }
        }
    }
    printf("\nvalue : %d \n", top);
    for (int i = top; i >= 0; i--)
    {
        printf("%d \n", st[i]);
    }

    return 0;
}

// arr1[] = arr2[]