#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "avl.h"
#include "marks_avl.h"

void merge_tree(TNODE **rootp1, TNODE **rootp2)
{
    // your implementation
    // use recursive algorithm to traverse tree rootp2,
    // get data of each node and insert into rootp1
    if (*rootp2 == NULL)
        return;
    else
    {
        insert(rootp1, (*rootp2)->data.name, (*rootp2)->data.score);
        merge_tree(rootp1, &(*rootp2)->left);
        merge_tree(rootp1, &(*rootp2)->right);
    }
}

void merge_data(MARKS *ds1, MARKS *ds2)
{
    // your implementation
    // call the merge_tree function to merge ds2->bst into da1->bst
    // update the stats of the merged data set using the stats of ds1 and ds2.
    merge_tree(&ds1->bst, &ds2->bst);
    ds1->stats.min = min(ds1->stats.min, ds2->stats.min);
    ds1->stats.max = max(ds1->stats.max, ds2->stats.max);
    ds1->stats.sum += ds2->stats.sum;
    ds1->stats.count += ds2->stats.count;
    ds1->stats.mean = ds1->stats.sum / ds1->stats.count;
}

// the following are adapted from marks_bst.c of A7Q2

void display_stats(MARKS *sd)
{
    printf("\nStatistics summary\n");
    printf("%s:%d\n", "count", sd->count);
    printf("%s:%.1f\n", "mean", sd->mean);
    printf("%s:%.1f\n", "stddev", sd->stddev);
}

void add_data(MARKS *sd, char *name, float score)
{
    if (search(sd->bst, name) == NULL)
    {
        insert(&sd->bst, name, score);

        // recompute statistics summary by adding new one
        int count = sd->count;
        float mean = sd->mean;
        float stddev = sd->stddev;
        sd->count = count + 1;
        sd->mean = (mean * count + score) / (count + 1);
        sd->stddev = sqrt(score * score / (count + 1.0) + (stddev * stddev + mean * mean) * (count / (count + 1.0)) - sd->mean * sd->mean);
    }
    else
        printf("record exit");
}

void remove_data(MARKS *sd, char *name)
{
    TNODE *np = NULL;
    if ((np = search(sd->bst, name)) != NULL)
    {
        float score = np->data.score;
        delete (&sd->bst, name);

        // recompute statistics summary by removing an old one
        int count = sd->count;
        float mean = sd->mean;
        float stddev = sd->stddev;
        sd->count = count - 1;
        sd->mean = (mean * count - score) / (count - 1.0);
        sd->stddev = sqrt((stddev * stddev + mean * mean) * (count / (count - 1.0)) - score * score / (count - 1.0) - sd->mean * sd->mean);
    }
    else
        printf("record not exit");
}

void display_marks(MARKS *dsp)
{
    display_inorder_lines(dsp->bst);
    printf("\nstatistics summary\n");
    printf("%s:%d\n", "count", dsp->count);
    printf("%s:%.1f\n", "mean", dsp->mean);
    printf("%s:%.1f\n", "stddev", dsp->stddev);
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
    char delimiters[] = ",\n";
    float score = 0;
    int count = 0;
    float mean = 0, stddev = 0;

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
            count++;
            mean += score;
            stddev += score * score;
            insert(&ds->bst, name, score);
        }
    }

    ds->count = count;
    mean /= count;
    ds->mean = mean;
    ds->stddev = sqrt(stddev / count - mean * mean);

    fclose(fp);
}

void report_data(MARKS *sd, char *filename)
{
    FILE *fp = fopen(filename, "w");

    print_to_file_inorder(sd->bst, fp);

    fprintf(fp, "\nStatistics summary\n");
    fprintf(fp, "%s:%d\n", "count", sd->count);
    fprintf(fp, "%s:%.1f\n", "mean", sd->mean);
    fprintf(fp, "%s:%.1f\n", "stddev", sd->stddev);
    fclose(fp);
}

void print_to_file_inorder(TNODE *root, FILE *fp)
{
    if (root)
    {
        if (root->left)
            print_to_file_inorder(root->left, fp);
        fprintf(fp, "%s,%.1f,%c\n", root->data.name, root->data.score, letter_grade(root->data.score));
        if (root->right)
            print_to_file_inorder(root->right, fp);
    }
}

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