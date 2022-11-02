#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np)
{
    np->next = NULL;
    if (qp->front == NULL)
    {
        qp->front = np;
        qp->rear = np;
    }
    else
    {
        qp->rear->next = np;
        qp->rear = np;
    }
}

NODE *dequeue(QUEUE *qp)
{
    NODE *np = qp->front;
    if (qp->front != NULL)
    {
        qp->front = qp->front->next;
        if (qp->front == NULL)
            qp->rear = NULL;
    }
    np->next = NULL;
    return np;
}

void clean_queue(QUEUE *qp)
{
    // your implementation, call clean(NODE **)
    NODE **np = &qp->front;
    clean(np);
}