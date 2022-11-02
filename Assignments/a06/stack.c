#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np)
{
    // your implementation
    if (sp->top == NULL)
    {
        sp->top = np;
    }
    else
    {
        np->next = sp->top;
        sp->top = np;
    }
}

NODE *pop(STACK *sp)
{
    // your implementation
    NODE *np = sp->top;
    if (sp->top != NULL)
    {
        sp->top = sp->top->next;
    }
    return np;
}

void clean_stack(STACK *sp)
{
    // your implementation,  use clean() function in common.h
    clean(&sp->top);
}