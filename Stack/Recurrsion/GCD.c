#include<stdio.h>
int GCD(int a, int b)
{
    int rem;
    rem = a%b;
    if(rem == 0)
    {
        return b;
    }
    else
        return GCD(b, rem);
}
int main()
{
    int num1, num2;
    printf("Enter two number two find GCD : ");
    scanf("%d", &num1);
    scanf("%d", &num2);
    int ans = GCD(num1, num2);
    printf("the GCD is eqqual to : %d ", ans);

    return 0;
}