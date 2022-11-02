#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void factorial(n){
    int ans = 1;
    int prev = 0;
    int count;
    for (int i = 1; i <= n; i++)
    {
        prev = ans;
        ans *= i;
        count = i;

        if (prev >= INT_MAX / i)
        {
            printf("overflow:%d!\n", count);
            return;
        }
        else
        {
            printf("%11d", ans);
            if (count % 4 == 0)
            {
                printf("\n");
            }
        }
    }
    if (count % 4 != 0)
    {
        printf("\n");
    }
    printf("%d!:%d\n", n, ans);
}

int main(int argc, char const *argv[])
{
    int num;
    int valid;
    char input[10];
    int is_string = 1;
    printf("factorial ");
    valid = scanf("%s", input);
    getchar();
    for (int i = 0; i < strlen(input); i++)
    {
        if(!isdigit(input[i])){
            is_string = 0;
        }
    }
    
    if (is_string)
    {
        num = atoi(input);
        if (num < 0)
        {
            printf("%s:invalid input", input);
        }else
        {
            factorial(num);
        }
    }
    else{
        printf("%s:invalid argument\n", input);
    }

        return 0;
}
