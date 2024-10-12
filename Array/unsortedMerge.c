#include<stdio.h>
int main()
{
    int arr1[] = {90, 56, 89, 77, 69};
    int arr2[] = {45, 88, 76, 99, 12, 58, 81};
    int merge[100];

    int leng1, leng2;
    leng1 = sizeof(arr1)/sizeof(arr1[0]);
    leng2 = sizeof(arr2)/sizeof(arr2[0]);

    int leng3 = leng1 + leng2;
    int index = 0;
    for (int i = 0; i < leng1; i++)
    {
        merge[index] = arr1[i];
        index++;
    }
    for (int j = 0; j < leng2; j++)
    {
        merge[index] = arr2[j];
        index++;
    }
    

    for (int i = 0; i < leng3; i++)
    {
        printf("%d \t", merge[i]);
    }
    
    return 0;
}