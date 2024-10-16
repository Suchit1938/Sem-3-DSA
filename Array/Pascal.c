#include <stdio.h>
int main()
{
    int arr[7][7];
    int row = 2, col;
    arr[0][0] = arr[1][0] = arr[1][1] = 1;
    while (row < 7)
    {
        arr[row][0] = 1;
        for (col = 1; col <= row; col++)
        {
            arr[row][col] = arr[row - 1][col - 1] + arr[row - 1][col];
        }
        row++;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("\n");
        for (int j = 0; j <= i; j++)
        {
            printf("\t %d", arr[i][j]);
        }
    }

    return 0;
}