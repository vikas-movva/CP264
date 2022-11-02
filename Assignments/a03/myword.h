#include <stdio.h>
#include <stdlib.h>
// structure definitions:
typedef struct word {
    char word[30];
    int frequency;
} WORD;

typedef struct words {
    WORD word_array[1000];
    int line_count;
    int word_count;
    int keyword_count;  // represent the number of distinct non-common words
} WORDSUMMARY;

/*
reads stop words from the common word file by filename, 
and puts them in the stop word dictionary data structure as an array of 26 strings, 
each string holds all stop words starting with the same alphabet, separated by comma “,”. 
The array of strings is passed parameter char *stopwords[], stopwords[i] holds the pointer of the i-th string.
*/
void set_stopword(char *filename, char *stopwords[]){
    FILE* fptr;
    fptr = fopen(filename, "r");

    fseek(fptr, 0, SEEK_END);
    long fsize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);  /* same as rewind(f); */

    char *string[fsize + 1];
    fread(string, fsize, 1, fptr);
    fclose(fptr);

    
string[fsize] = 0;
}

/*
checks if the given *word is contained in a given string str, 
returns 1 if yes and 0 otherwise. 
For example, if str is “the,this,that”, word is “this”, then it returns 1.
*/
int contain_word(char *str, char *word);

/*
checks if the given word is contained in stop word dictionary char stopwords[], 
it returns 1 if true otherwise 0.
*/
int is_stopword(char *stopwords[], char *word);

/*
opens and reads text file of name passed by *filename line by line. 
For each line, it gets each word, if it is not a stop word, 
check if it is already in array words->word_array, 
if yes, increases its frequency by 1, 
otherwise inserts it to the end of the word_array and set its frequency 1. 
Meantime, it updates the count information.
*/
int process_word(char *filename, WORDSUMMARY *words, char *stopwords[]);

/*
saves the data of WORDSUMMARY words to file of name passed by filename in specified format.
*/
int save_to_file(char *filename, WORDSUMMARY *words);