#include "dllist.h"
#include <stdlib.h>
#include <stdio.h>

NODE *new_node(char data)
{
    NODE *np = (NODE *)malloc(sizeof(NODE));
    np->data = data;
    np->next = NULL;
    np->prev = NULL;
    return np;
}

void display_forward(NODE *np)
{
    while (np != NULL)
    {
        printf("%c", np->data);
        np = np->next;
    }
    printf("\n");
}

void display_backward(NODE *np)
{
    while (np != NULL)
    {
        printf("%c", np->data);
        np = np->prev;
    }
    printf("\n");
}

void insert_start(NODE **startp, NODE **endp, NODE *new_np)
{
    if (*startp == NULL)
    {
        *startp = new_np;
        *endp = new_np;
    }
    else
    {
        new_np->next = *startp;
        (*startp)->prev = new_np;
        *startp = new_np;
    }
}

void insert_end(NODE **startp, NODE **endp, NODE *new_np)
{
    if (*startp == NULL)
    {
        *startp = new_np;
        *endp = new_np;
    }
    else
    {
        new_np->prev = *endp;
        (*endp)->next = new_np;
        *endp = new_np;
    }
}

void delete_start(NODE **startp, NODE **endp)
{
    if (*startp == NULL)
    {
        return;
    }
    else if (*startp == *endp)
    {
        free(*startp);
        *startp = NULL;
        *endp = NULL;
    }
    else
    {
        NODE *np = *startp;
        *startp = np->next;
        (*startp)->prev = NULL;
        free(np);
    }
}

void delete_end(NODE **startp, NODE **endp)
{
    if (*startp == NULL)
    {
        return;
    }
    else if (*startp == *endp)
    {
        free(*startp);
        *startp = NULL;
        *endp = NULL;
    }
    else
    {
        NODE *np = *endp;
        *endp = np->prev;
        (*endp)->next = NULL;
        free(np);
    }
}

void clean(NODE **startp, NODE **endp)
{
    while (*startp != NULL)
    {
        delete_start(startp, endp);
    }
}