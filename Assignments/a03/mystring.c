#include "mystring.h"

int str_length(char *s)
{
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }

    return count;
};

int word_count(char *s)
{
    int count = 0;
    int str_len = str_length(s);
    // loop through string
    for (int i = 1; i < str_len; i++)
    {
        // check if white space is surrounded by non whitespace characters
        if (s[i] == ' ' && s[i + 1] != ' ' && s[i - 1] != ' ')
            count++;
    }
    // add a count to the end if the last character is not a whitespace character
    if (s[str_len - 1] != ' ')
    {
        count++;
    }

    return count;
};

void lower_case(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] < 91 && s[i] > 64)
        {
            s[i] = s[i] + 32;
        }
    }
}

void trim(char *s)
{

    int i, x;
    for (i = x = 0; s[i]; ++i)
        if (s[i] != ' ' || (i > 0 && s[i - 1] != ' '))
            s[x++] = s[i];
    s[x] = '\0';
}

// int main(int argc, char const *argv[])
// {
//     char s[50] = "RanDom     striNg       namE";

//     int count = word_count(s);
//     printf("%d\n", count);
//     lower_case(s);
//     printf("%s\n", s);
//     trim(s);
//     printf("%s\n", s);
//     return 0;
// }
