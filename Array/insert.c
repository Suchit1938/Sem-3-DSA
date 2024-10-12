#include<stdio.h>
int main()
{
    // int arr[5];
    // int upper_bound;
    // printf("Enter initial number of element in array : ");
    // scanf("%d", &upper_bound);
    // for (int i = 0; i < upper_bound; i++)
    // {
    //     printf("Enter element %d : ", i);
    //     scanf("%d", &arr[i]);
    // }
    // arr[upper_bound] = 1938;
    // upper_bound = upper_bound + 1;
    // arr[upper_bound] = 8391;

    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d \t", arr[i]);
    // }

    int arr[10], n, val, pos;
    printf("Enter the initaial number of element is array : ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the value you want ti insert : ");
    scanf("%d", &val);

    printf("Enter the pos where you want to insert the element : ");
    scanf("%d", &pos);

    for (int i = n-1; i >= pos; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[pos] = val;
    n = n + 1; 
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", arr[i]);
    }
    
    return 0;
}