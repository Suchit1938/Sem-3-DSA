#include<stdio.h>
int fact(int n)
{
    if(n == 1)
        return 1;
    else
        return (n*fact(n- 1));
}
int main()
{
    int n;
    printf("Enter a number to find factorial of : ");
    scanf("%d", &n);
    int value = fact(n);
    printf("%d", value);
    return 0;
}