#include<stdio.h>
int main()
{
    int arr[] = {10, 20, 30, 40, 40, 50};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("The number of element in array is %d ", size);
    return 0;
}