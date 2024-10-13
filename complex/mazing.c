#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define EXIT_ROW 7
#define EXIT_COL 7
typedef struct
{
    short int vert;
    short int horiz;
} offsets;

offsets move[8] = {
    {-1, 0}, // N
    {-1, 1}, // NE
    {0, 1},  // E
    {1, 1},  // SE
    {1, 0},  // S
    {1, -1}, // SW
    {0, -1}, // W
    {-1, -1} // NW
}; /* array of moves for each direction */

typedef struct
{
    int row;
    int col;
    int dir;
} element;

element stack[MAX_STACK_SIZE];
int top = -1;

void push(element item)
{
    if (top >= MAX_STACK_SIZE - 1)
    {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

element pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}
int main() {
    
   int maze[8][8] = {
        { 0, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 0, 1, 1 },
        { 1, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1 },
        { 1, 0, 0, 0, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 0, 1, 0, 1 },
        { 1, 1, 1, 1, 0, 0, 1, 0 }
    };
    int mark[8][8] = { 0 };
    int row, col, next_row, next_col, dir, found = 0;
    element position;

    mark[0][0] = 1; //starting position
    top = 0;

    stack[top].row = 0;
    stack[top].col = 0;
    stack[top].dir = 0;

    while (top > -1 && !found) {
        position = pop();
        row = position.row;
        col = position.col;
        dir = position.dir;

        while (dir < 8 && !found) {
            printf("moving %d %d\n", move[0].vert,move[0].horiz);
            next_row = row + move[dir].vert;
            next_col = col + move[dir].horiz;
        // printf("%d,%d\n", next_row,next_row);

            if (next_row == EXIT_ROW && next_col == EXIT_COL) {
                found = 1;
            } else if (maze[next_row][next_col] == 0 && mark[next_row][next_col] == 0) {
                mark[next_row][next_col] = 1;
                position.row = row;
                position.col = col;
                position.dir = ++dir;
                push(position);
                row = next_row;
                col = next_col;
                dir = 0;
            } else {
                ++dir;
            }
        }
       
    }

    if (found) {
        
         for (int i = 0; i <= top; i++)
        {
            printf("%d %d %d\n",stack[i].row,stack[i].col,stack[i].dir);
        }
        
        printf("Path found to exit\n");
    } else {
        printf("No path found\n");
    }

    return 0;
}