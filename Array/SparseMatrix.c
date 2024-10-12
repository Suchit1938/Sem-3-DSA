#include <stdio.h>
int main()
{
    int arr[4][4] = {1, 0, 0, 0,
                     0, 0, 2, 0,
                     0, 5, 0, 5,
                     9, 0, 0, 0};

    int Sparse[10][3] = {0};
    int k = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (arr[i][j] != 0)
            {
                Sparse[0][k] = i;
                Sparse[1][k] = j;
                Sparse[2][k] = arr[i][j];
                k++;
            }
        }
    }

    printf("row\tcolumn\tvalue\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t%d\t%d\n", Sparse[0][i], Sparse[1][i], Sparse[2][i]);
    }

    return 0;
}