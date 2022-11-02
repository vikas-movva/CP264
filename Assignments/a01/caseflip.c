#include <stdio.h>
#define FALSE 0
#define TRUE 1


// A function that flips the case of a given letter
// character validation is expected to be done before calling the function
char caseflip(char ch){
    int letter = (int) ch;

    if (letter < 90)
    {
        // lowers the case of the letter
        letter += 32;

    }else{
        // increases the case of the letter
        letter -= 32;

    }
    ch = (char)letter;
    return ch;
}

int main()
{
    char input = 0;
    int cont = TRUE;

    while (input != 42)
    {
        printf("Please enter a character\n");
            input = getchar();
            getchar();
            printf("%c:", input);
            if ((int)input >= 65 && (int)input <= 90 || (int)input >= 97 && (int)input <= 122)
            {
                printf("%d", (int)input);
                input = caseflip(input);
                printf(" ,%c\n", input);
        }
        else if (input == 42)
        {
            printf("quit\n");
        }
        else
        {
            printf("invalid\n");
        }
    }

    return 0;
}
