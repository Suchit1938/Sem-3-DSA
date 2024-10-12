#include<stdio.h>

long long int myExp(int x, int y)
{
    if(y == 0)
    {
        return 1;
    }
    else
    {
        return (x * myExp(x,y-1));
    }
}
int main()
{
    int x = 2, y = 30;
    printf("The answer is : %lld", myExp(x,y));
    return 0;
}