#include <stdio.h>
int main()
{
    int arr[10], n, pos, num;
    printf("Enter the initaial number of element is array : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter the pos where you want to delete the element : ");
    scanf("%d", &pos);

    for (int i = pos; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n = n - 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    return 0;
}

