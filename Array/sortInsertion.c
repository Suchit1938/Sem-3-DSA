#include <stdio.h>
int main()
{
    int arr[10], n, val, pos;
    printf("Enter the initaial number of element is array : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value you want to insert : ");
    scanf("%d", &val);

    for (int i = 0; i < n; i++)
    {
        if (val < arr[i])
        {
            for (int j = n - 1; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i] = val;
            break;
        }
    }
    n = n + 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d \t ", arr[i]);
    }

    return 0;
}