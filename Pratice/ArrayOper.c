#include <stdio.h>

void CreateArray(int n, int arr[])
{

    for (int i = 0; i < n; i++)
    {
        printf("Enter arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }
}
void Display(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] : %d\n", i, arr[i]);
    }
}
void Insertion(int arr[], int *n, int pos, int num)
{
    if(pos < 0 || pos > *n)
    {
        printf("Invalid Position to insert");
        return;
    }
    for (int i = *n; i > pos; --i) // 0, 1, 2, 3, 4
    {
        arr[i] = arr[i-1];
    }
    
}
int main()
{
    int N, option;
    printf("Enter the number of elements in Array : ");
    scanf("%d", &N);
    int arr[N];
    CreateArray(N, arr);
    printf("\n1. Display\n");
    printf("2. Insertion\n");
    printf("3. Deletion\n");
    printf("4. EXIT\n");
    printf("Enter a option to perform operation in a array : ");
    scanf("%d", &option);
    int pos, value, num;
    switch (option)
    {
    case 1:
        printf("**Display**");
        Display(N, arr);
        break;
        // case 2:
        //     printf("Enter a number to insert in array : ");
        //     scanf("%d", &num);
        //     printf("Enter the pos to insert in array : ");
        //     scanf("%d", &pos);
        //     Insertion(&num, pos);
        //     break;
        // case 3:
        //     printf("Enter the pos to delete an number : ");
        //     scanf("%d", &pos);
        //     value = Deletion(pos);
        //     printf("The deleted value is %d ", value);
        //     break;
        // case 4:
        //     printf("Exiting the Programme");
        //     return 0;
        // default:
        //     printf("Enter the correct choice of option : ");
    }
    return 0;
}