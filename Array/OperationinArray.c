#include <stdio.h>

void createArray(int arr[], int n)
{
    printf("Enter %d elements for the array:\n", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n)
{
    printf("Array elements:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *n, int pos, int elem)
{
    if (pos < 0 || pos > *n)
    {
        printf("Invalid position for insertion.\n");
        return;
    }

    for (int i = *n; i > pos; --i)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = elem;
    (*n)++;
    printf("Element %d inserted at position %d.\n", elem, pos);
}

void deleteElement(int arr[], int *n, int pos)
{
    if (pos < 0 || pos >= *n)
    {
        printf("Invalid position for deletion.\n");
        return;
    }

    for (int i = pos; i < *n - 1; ++i)
    {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Element at position %d deleted.\n", pos);
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    createArray(arr, n);

    int choice, elem, pos;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Display array elements\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayArray(arr, n);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &elem);
            printf("Enter the position to insert at: ");
            scanf("%d", &pos);
            insertElement(arr, &n, pos, elem);
            displayArray(arr, n);
            break;
        case 3:
            printf("Enter the position to delete from: ");
            scanf("%d", &pos);
            deleteElement(arr, &n, pos);
            displayArray(arr, n);
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
