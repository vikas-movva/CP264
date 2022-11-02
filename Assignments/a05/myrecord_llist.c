#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "myrecord_llist.h"

void display(NODE *start)
{
    NODE *np = start;
    while (np != NULL)
    {
        printf("%s,%.1f\n", np->data.name, np->data.score);
        np = np->next;
    }
}

NODE *search(NODE *startp, char *name)
{
    NODE *np = startp;
    while (np != NULL)
    {
        if (strcmp(np->data.name, name) == 0)
        {
            return np;
        }
        np = np->next;
    }
    return NULL;
}

void insert(NODE **startp, char *name, float score)
{
    NODE *np = (NODE *)malloc(sizeof(NODE));
    strcpy(np->data.name, name);
    np->data.score = score;
    np->next = NULL;
    if (*startp == NULL)
    {
        *startp = np;
    }
    else
    {
        NODE *prev = NULL;
        NODE *curr = *startp;
        while (curr != NULL && strcmp(curr->data.name, name) < 0)
        {
            prev = curr;
            curr = curr->next;
        }
        if (prev == NULL)
        {
            np->next = *startp;
            *startp = np;
        }
        else
        {
            np->next = curr;
            prev->next = np;
        }
    }
}

int delete (NODE **startp, char *name)
{
    NODE *prev = NULL;
    NODE *curr = *startp;
    while (curr != NULL && strcmp(curr->data.name, name) != 0)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return 0;
    }
    else
    {
        if (prev == NULL)
        {
            *startp = curr->next;
        }
        else
        {
            prev->next = curr->next;
        }
        free(curr);
        return 1;
    }
}

void clean(NODE **startp)
{
    NODE *np = *startp;
    while (np != NULL)
    {
        NODE *next = np->next;
        free(np);
        np = next;
    }
    *startp = NULL;
}

// the following functions are adapted and modified from previous assignments.

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

int import_data(NODE **startp, char *filename)
{
    char line[40], name[20];
    char *result = NULL;
    char delimiters[] = ",";
    float score = 0;
    int count = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        result = strtok(line, delimiters);
        strcpy(name, result);
        result = strtok(NULL, delimiters);
        score = atof(result);
        insert(startp, name, score);
        count++;
    }
    fclose(fp);

    return count;
}

REPORT report_data(NODE *start, char *filename)
{
    REPORT report = {};
    NODE *np = start;
    int count = 0;
    float mean = 0;
    float stddev = 0;

    FILE *fp = fopen(filename, "w");
    while (np != NULL)
    {
        count++;
        mean += np->data.score;
        stddev += np->data.score * np->data.score;
        fprintf(fp, "%s,%3.1f,%c\n", np->data.name, np->data.score, letter_grade(np->data.score));
        np = np->next;
    }
    fclose(fp);

    mean /= count;
    stddev = sqrt(stddev / count - mean * mean);
    report.count = count;
    report.mean = mean;
    report.stddev = stddev;
    return report;
}