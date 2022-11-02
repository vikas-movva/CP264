#include <stdio.h>
#include <math.h>

void display_polynomial(float p[], int n, float x)
{
    int exp = n - 1;
    for (int i = 0; i < n; i++, exp--)
    {
        printf("%.2f*%.2f^%d", p[i], x, exp);
        if (i != n - 1)
        {
            printf("+");
        }
    }
}

float horner(float p[], int n, float x)
{
    float ans = p[0];
    for (int i = 1; i < n; i++)
    {
        ans = ans * x + p[i];
    }
    return ans;
}

float bisection(float p[], int n, float a, float b)
{
    int count = 0;
    float c;
    while (count <= 100)
    {
        c = (a + b) / 2;
        if (horner(p, n, c) == 0 || (b - a) / 2 < 0.000001)
        {
            return c;
        }
        count++;
        if (horner(p, n, c) / fabs(horner(p, n, c)) == horner(p, n, a) / fabs(horner(p, n, a)))
        {
            a = c;
        }
        else
        {
            b = c;
        }
    }
    return 0;
}