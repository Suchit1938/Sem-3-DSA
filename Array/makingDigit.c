#include<stdio.h>
#include<math.h>

int main()
{
    int digit[10], noOfdigits;
    printf("Enter number of digits : ");
    scanf("%d", &noOfdigits);
    for (int i = 0; i < noOfdigits; i++)
    {
        printf("Enter the digit on the position %d : ", i+1);
        scanf("%d", &digit[i]);
    }
    int number = 0;
    for (int i = 0; i < noOfdigits; i++)
    {
        number = number + digit[i]*pow(10,i);
        // printf("%d \n", number);
    }
    int num = 0;
    for (int i = 0; i < noOfdigits; i++)
    {
        num = num*10 + digit[i];
    }
    
    printf("The number is %d \n", number);
    printf("The num is %d", num);
}