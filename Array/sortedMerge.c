#include <stdio.h>
int main()
{
    int arr1[] = {1, 4, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 5};
    int merge[100];

    int leng1, leng2;
    leng1 = sizeof(arr1) / sizeof(arr1[0]);
    leng2 = sizeof(arr2) / sizeof(arr2[0]);

    int leng3 = leng1 + leng2;

    int i = 0, j = 0, k = 0;
    while (i < leng1 && j < leng2)
    {
        if (arr1[i] < arr2[j])
        {
            merge[k] = arr1[i];
            k++;
            i++;
        }
        else
        {
            merge[k] = arr2[j];
            k++;
            j++;
        }
    }

    while (i < leng1)
    {
        merge[k] = arr1[i];
        k++;
        i++;
    }

    while (j < leng2)
    {
        merge[k] = arr2[j];
        k++;
        j++;
    }
    
    for (int i = 0; i < k; i++)
    {
        printf("%d \t", merge[i]);
    }
    

    return 0;
}