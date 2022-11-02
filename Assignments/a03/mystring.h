// computes and returns the number of characters of string passed by s (including space).
int str_length(char *s)
{
    int count = 0;
    while (s[count] != '\0')
    {
        count++;
    }

    return count;
};

// computes and returns the number of words of string passed by s.
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

// changes upper case to lower case of string passed by s.
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

// removes the none necessary empty spaces of string passed by s.
void trim(char *s)
{

    int i, x;
    for (i = x = 0; s[i]; ++i)
        if (s[i] != ' ' || (i > 0 && s[i - 1] != ' '))
            s[x++] = s[i];
    s[x] = '\0';
}