#include <stdio.h>
int main()
{
    int row, col;

    printf("Enter no of rows : ");
    scanf("%d", &row);

    printf("Enter no of columns : ");
    scanf("%d", &col);

    int sparseMatrix[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    printf("Printting the matrix \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d \t", sparseMatrix[i][j]);
        }
        printf("\n");
    }

    int size = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(sparseMatrix[i][j] != 0)
            {
                size++;
            }
        }
    }

    
    
    
    return 0;
}