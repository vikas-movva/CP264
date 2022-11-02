#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void quadratic(int a,int b,int c){
    int complex = 0;
    int ans[3];
    if (a != 0)
    {
        int d;
        d = pow((double)b, 2) - (4 * a * c);
        if (d < 0)
        {
            d = abs(d);
            printf("The equation has two complex roots\n");
            printf("real:%7f\n", (double)-b/(2*a));
            printf("imaginary:%7f\n", sqrt(d)/(2*a));
        }else if (d == 0)
        {
            printf("The equation has two equal real roots\n");
            printf("x:%7f\n", (double)-b / (2 * a));
        }else{
            printf("The equation has two distinct real roots\n");
            printf("x1:%7f\n", ((double)-b + sqrt(d))/ (2 * a));
            printf("x2:%7f\n", ((double)-b - sqrt(d))/ (2 * a));
        }
    }
}


int main(int argc, char const *argv[])
{
    int a, b, c, valid;
    char s[32];
    a = 1, b = 0, c = 0;

    while (!(a==0&&b==0&&c==0))
    {
    printf("Please enter the coefficients a, b, c\n");
    valid = scanf("%d,%d,%d",&a,&b,&c);
    if (valid == 3)
    {
    quadratic(a, b, c);
    }else{
        printf("input:Invalid input\n");
        scanf("%s",s);
    }
    }
    printf("input:quit\n");


    return 0;
}
