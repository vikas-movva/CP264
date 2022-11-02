/*
--------------------------------------------------
Project: cp264oc-a4q1
File:    myrecord.h header file
Author:  VM
Version  2022-09-30
--------------------------------------------------
*/

#ifndef MYRECORD_H
#define MYRECORD_H

/*
Define a structure named RECORD to hold a person's name of 20 characters and the score of float type.
*/
typedef struct
{
    char name[20];
    float score;
} RECORD;

/*
Define a structure named REPORT containing fields int count, float mean, float stddev (standard deviation).
*/
typedef struct
{
    int count;
    float mean;
    float stddev;
} REPORT;

/*
This function converts a float score to a letter grade according to ranges  S=[90, 100], A=[80, 90), B=[70, 80), C=[60, 70), D=[50,60), F=[0,50), and returns the letter grade.
*/
char letter_grade(float score);

/*
This function imports data from file of name passed by filename, and stores all record entries in an array of RECORD dataset[], and returns the number of records read.
*/
int import_data(RECORD dataset[], char *filename);

/*
This function computes the average score and standard deviation of the score values of dataset[], and returns the results by the RECORD type. It also outputs name and letter grade to file of name passed by filename, using format "%s,%c\n"
*/
REPORT report_data(RECORD dataset[], int n, char *filename);

#endif