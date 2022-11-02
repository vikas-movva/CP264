/*
--------------------------------------------------
Project: cp264oc-a4q1
File:    myrecord.c code file
Author:  VM
Version  2022-09-30
--------------------------------------------------
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "myrecord.h"

#define MAX_LINE 100

/*
This function converts a float score to a letter grade according to ranges  S=[90, 100], A=[80, 90), B=[70, 80), C=[60, 70), D=[50,60), F=[0,50), and returns the letter grade.
*/
char letter_grade(float s)
{
    if (s >= 90)
        return 'S';
    else if (s >= 80)
        return 'A';
    else if (s >= 70)
        return 'B';
    else if (s >= 60)
        return 'C';
    else if (s >= 50)
        return 'D';
    else
        return 'F';
}

/*
This function imports data from file of name passed by filename, and stores all record entries in an array of RECORD dataset[], and returns the number of records read.
*/
int import_data(RECORD dataset[], char *filename)
{
    FILE *fp;
    char line[MAX_LINE];
    int i = 0;
    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("ERROR: cannot open file %s\n", filename);
        return -1;
    }
    while (fgets(line, MAX_LINE, fp) != NULL)
    {
        strcpy(dataset[i].name, strtok(line, ","));
        dataset[i].score = atof(strtok(NULL, ","));
        i++;
    }
    fclose(fp);
    return i;
}

/*
This function computes the average score and standard deviation of the score values of dataset[], and returns the results by the RECORD type. It also outputs name and letter grade to file of name passed by filename, using format "%s,%c
*/
REPORT report_data(RECORD dataset[], int n, char *filename)
{
    REPORT report;
    FILE *fp;
    int i;
    float sum = 0;
    float sum_sq = 0;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("ERROR: cannot open file %s\n", filename);
        report.count = -1;
        return report;
    }
    for (i = 0; i < n; i++)
    {
        sum += dataset[i].score;
        sum_sq += dataset[i].score * dataset[i].score;
    }
    report.count = n;
    report.mean = sum / n;
    report.stddev = sqrt((sum_sq - sum * sum / n) / (n - 1));
    for (i = 0; i < n; i++)
        fprintf(fp, "%s,%c\n", dataset[i].name, letter_grade(dataset[i].score));
    fclose(fp);
    return report;
}