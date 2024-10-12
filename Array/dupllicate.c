#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array : ");
    scanf("%d", &n);
    int arr[n];
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d element : ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                flag = 1;
                printf("The duplicate element found at position : %d and %d \n", i,j);
            }
        }
    }
    if(flag = 0) {
        printf("No duplicate element ");
    }
    return 0;
}