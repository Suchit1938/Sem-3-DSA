#include<stdio.h>
int main()
{
    int arr[10], n, num;
    printf("Enter the initaial number of element is array : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the pos where you want to delete the element : ");
    scanf("%d", &num);

    for (int i = 0; i < n; i++)
    {
        if(arr[i] == num)
        {
            for (int j = i; j < n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
        }
    }
    n = n - 1;
    return 0;
}