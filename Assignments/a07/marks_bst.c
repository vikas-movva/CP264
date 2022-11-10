#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "bst.h"
#include "marks_bst.h"

/* add a record (name, score) into the bst and update the stats info incrementally */
void add_data(MARKS *dsp, char *name, float score)
{
    insert(&dsp->bst, name, score);
    dsp->count++;
    dsp->mean = dsp->mean + (score - dsp->mean) / dsp->count;
    dsp->stddev = sqrt((dsp->stddev * dsp->stddev * (dsp->count - 1) + (score - dsp->mean) * (score - dsp->mean)) / dsp->count);
}

/* delete a record of name from the bst and update the stats info incrementally */
void remove_data(MARKS *dsp, char *name)
{
    TNODE *temp = search(dsp->bst, name);
    if (temp != NULL)
    {
        dsp->count--;
        dsp->mean = dsp->mean - (temp->data.score - dsp->mean) / dsp->count;
        dsp->stddev = sqrt((dsp->stddev * dsp->stddev * (dsp->count + 1) - (temp->data.score - dsp->mean) * (temp->data.score - dsp->mean)) / dsp->count);
        delete (&dsp->bst, name);
    }
}

// the following are adopted and modified from previous assignments
char letter_grade(float s)
{
    char r = 'F';
    if (s >= 90)
        r = 'S';
    else if (s >= 80)
        r = 'A';
    else if (s >= 70)
        r = 'B';
    else if (s >= 60)
        r = 'C';
    else if (s >= 50)
        r = 'D';
    else
        r = 'F';
    return r;
}

void display_marks(MARKS *dsp)
{
    printf("%-15s%d\n", "count", dsp->count);
    printf("%-15s%3.1f\n", "mean", dsp->mean);
    printf("%-15s%3.1f\n", "stddev", dsp->stddev);
    display_inorder(dsp->bst);
}

void clean_marks(MARKS *dsp)
{
    clean_tree(&dsp->bst);
    dsp->count = 0;
    dsp->mean = 0;
    dsp->stddev = 0;
}

void import_data(MARKS *ds, char *filename)
{
    char line[40], name[20];
    FILE *fp = fopen(filename, "r");
    char *result = NULL;
    float score = 0;
    char delimiters[] = ",\n";

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        result = strtok(line, delimiters);
        if (result)
        {
            strcpy(name, result);
            result = strtok(NULL, delimiters);
            score = atof(result);
            add_data(ds, name, score);
        }
    }
    fclose(fp);
}

void print_to_file_inorder(TNODE *root, FILE *fp)
{
    if (root)
    {
        if (root->left)
            print_to_file_inorder(root->left, fp);
        fprintf(fp, "%s,%3.1f,%c\n", root->data.name, root->data.score, letter_grade(root->data.score));
        if (root->right)
            print_to_file_inorder(root->right, fp);
    }
}

void report_data(MARKS *dsp, char *filename)
{
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%s:%d\n", "count", dsp->count);
    fprintf(fp, "%s:%.0f\n", "mean", dsp->mean);
    fprintf(fp, "%s:%.0f\n", "stddev", dsp->stddev);
    print_to_file_inorder(dsp->bst, fp);
    fclose(fp);
}