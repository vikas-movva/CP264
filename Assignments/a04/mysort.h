/*
--------------------------------------------------
Project: cp264oc-a4q1
File:    mysort.h header file
Author:  HBF
Version  2021-05-11
--------------------------------------------------
*/

#ifndef MYSORT_H
#define MYSORT_H

// define enum type BOOLEAN
typedef enum
{
    false = 0,
    true = 1
} BOOLEAN;

void select_sort(int *a, int left, int right);
BOOLEAN is_sorted(int *a, int left, int right);
void quick_sort(int *a, int left, int right);

#endif