#ifndef BIGINT_H
#define BIGINT_H
#include "dllist.h"

/*
Define structure BIGINT with fields:
start : A pointer points to the start NODE of a doubly linked list
end   : A pointer points to the end NODE of a doubly linked list
*/
typedef struct BIGINT
{
    NODE *start;
    NODE *end;
} BIGINT;

BIGINT bigint(char *p);

void display_bigint(BIGINT bignumber);

void clean_bigint(BIGINT *bignumberp);

BIGINT add(BIGINT op1, BIGINT op2);

BIGINT Fibonacci(int n);

#endif