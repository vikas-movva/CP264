#include <stdio.h>
#include "matrix.h"

void display_matrix(int *m, int n)
{
    int *p = m, i, j;
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%4d", *p++);
    }
    printf("\n");
}

int sum(int *m, int n)
{
    int *p = m, i, j;
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            sum += *p;
            p++;
        }
    }
    return sum;
}
int is_magic_square(int *m, int n)
{
    // init variables
    int sum = 0;
    int target = sum;
    int *p = m;
    // check sum for first row and set it as the target
    for (int i = 0; i < n; i++)
    {
        sum += *p;
        p++;
    }
    target = sum;
    // reset sum
    sum = 0;
    // check sum for rows 2, 3
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n; i++)
        {
            sum += *p;
            p++;
        }
        if (sum != target)
        {
            return 0;
        }

        sum = 0;
    }
    // reset pointer to start of array
    p = m;
    // check sums for columns
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {

            sum += *p;
            p += n;
        }
        if (sum != target)
        {
            return 0;
        }

        sum = 0;
        p = m;
        p += j + 1;
    }
    // check sums for diagonal top left to bottom right
    p = m;
    for (int i = 0; i < n; i++)
    {

        sum += *p;
        p += n + 1;
    }
    if (sum != target)
    {
        return 0;
    }

    sum = 0;
    // check sums for diagonal top right to bottom left
    p = m;
    p += n - 1;
    for (int i = 0; i < n; i++)
    {

        sum += *p;
        p += n - 1;
    }
    if (sum != target)
    {
        return 0;
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    int matrix[3][3] = {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}};
    int *ptr = matrix;
    display_matrix(ptr, 3);
    printf("%d\n", sum(ptr, 3));
    printf("is magic square: %d\n", is_magic_square(ptr, 3));
    return 0;
}
