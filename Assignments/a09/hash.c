#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hash.h"

int hash(char *word)
{
    unsigned int hash = 0, i;
    for (i = 0; word[i] != '\0'; i++)
    {
        hash = 31 * hash + word[i];
    }
    return hash % htsize;
}

HTNODE *new_hashnode(char *name, int value)
{
    HTNODE *new = (HTNODE *)malloc(sizeof(HTNODE));
    strcpy(new->name, name);
    new->value = value;
    return new;
}

HASHTABLE *new_hashtable(int size)
{
    HASHTABLE *ht = (HASHTABLE *)malloc(sizeof(HASHTABLE));
    ht->hnp = (HTNODE **)malloc(sizeof(HTNODE **) * size);
    int i;
    for (i = 0; i < size; i++)
        *(ht->hnp + i) = NULL; // initialize to NULL
    ht->size = size;
    ht->count = 0;
    return ht;
}

HTNODE *search(HASHTABLE *ht, char *name)
{
    int index = hash(name);
    HTNODE *current = *(ht->hnp + index);
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}

int insert(HASHTABLE *ht, HTNODE *np)
{
    int index = hash(np->name);
    HTNODE *current = ht->hnp[index];
    while (current != NULL)
    {
        if (strcmp(current->name, np->name) == 0)
        {
            current->value = np->value;
            free(np);
            return 0;
        }
        current = current->next;
    }
    np->next = ht->hnp[index];
    ht->hnp[index] = np;
    ht->count++;
    return 1;
}

int delete (HASHTABLE *ht, char *name)
{
    int index = hash(name);
    HTNODE *current = ht->hnp[index];
    HTNODE *previous = NULL;
    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (previous == NULL)
            {
                ht->hnp[index] = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            ht->count--;
            return 1;
        }
        previous = current;
        current = current->next;
    }
    return 0;
}

// you can use this function in your program
void clean_hash(HASHTABLE **htp)
{
    if (*htp == NULL)
        return;
    HASHTABLE *ht = *htp;
    HTNODE *sp = ht->hnp[0], *p, *temp;
    int i;
    for (i = 0; i < ht->size; i++)
    {
        p = ht->hnp[i];
        while (p)
        {
            temp = p;
            p = p->next;
            free(temp);
        }
        ht->hnp[i] = NULL;
    }
    free(ht->hnp);
    ht->hnp = NULL;
    *htp = NULL;
}

// you can use this function in your program
void display_hashtable(HASHTABLE *ht, int option)
{
    int i = 0;
    HTNODE *p;
    if (option == 0)
    {
        printf("size:  %d\n", ht->size);
        printf("count: %d\n", ht->count);
        printf("hash data:\nindex: list of the data elements");
        for (i = 0; i < ht->size; i++)
        {
            p = *(ht->hnp + i);
            if (p)
                printf("\n%2d: ", i);

            while (p)
            {
                printf("(%s, %d) ", p->name, p->value);
                p = p->next;
            }
        }
        printf("\n");
    }
    else
    {

        for (i = 0; i < ht->size; i++)
        {
            p = *(ht->hnp + i);
            while (p)
            {
                printf("%s=%d\n", p->name, p->value);
                p = p->next;
            }
        }
    }
}