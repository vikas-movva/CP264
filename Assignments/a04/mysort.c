/*
--------------------------------------------------
Project: cp264oc-a4q1
File:    mysort.c code file
Author:  VM
Version  2022-09-30
--------------------------------------------------
*/
#include "mysort.h"

BOOLEAN is_sorted(int *a, int left, int right)
{
    int i;
    for (i = left; i < right; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}

void select_sort(int *a, int left, int right)
{
    int i, j, min, temp;
    for (i = left; i < right; i++)
    {
        min = i;
        for (j = i + 1; j <= right; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void quick_sort(int *a, int left, int right)
{
    int i, j, pivot, temp;
    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = a[left];
        do
        {
            do
                i++;
            while (a[i] < pivot && i <= right);
            do
                j--;
            while (a[j] > pivot);
            if (i < j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        } while (i < j);
        temp = a[left];
        a[left] = a[j];
        a[j] = temp;
        quick_sort(a, left, j - 1);
        quick_sort(a, j + 1, right);
    }
}

void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}