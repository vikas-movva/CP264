#include <stdio.h>
#include <stdlib.h>
#include "edgelist.h"

EDGELIST *new_edgelist()
{
  EDGELIST *el = (EDGELIST *)malloc(sizeof(EDGELIST));
  el->size = 0;
  el->start = NULL;
  el->end = NULL;
  return el;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight)
{
  EDGE *e = (EDGE *)malloc(sizeof(EDGE));
  e->from = from;
  e->to = to;
  e->weight = weight;
  e->next = NULL;
  if (g->start == NULL)
  {
    g->start = e;
    g->end = e;
  }
  else
  {
    g->end->next = e;
    g->end = e;
  }
  g->size++;
}

void add_edge_start(EDGELIST *g, int from, int to, int weight)
{
  EDGE *e = (EDGE *)malloc(sizeof(EDGE));
  e->from = from;
  e->to = to;
  e->weight = weight;
  e->next = g->start;
  if (g->start == NULL)
  {
    g->start = e;
    g->end = e;
  }
  else
  {
    g->start = e;
  }
  g->size++;
}

int weight_edgelist(EDGELIST *g)
{
  int weight = 0;
  EDGE *e = g->start;
  while (e != NULL)
  {
    weight += e->weight;
    e = e->next;
  }
  return weight;
}

void clean_edgelist(EDGELIST **gp)
{
  EDGELIST *g = *gp;
  EDGE *temp, *p = g->start;
  while (p)
  {
    temp = p;
    p = p->next;
    free(temp);
  }
  free(g);
  *gp = NULL;
}

void display_edgelist(EDGELIST *g)
{
  if (g == NULL)
    return;
  printf("size:%d\n", g->size);
  printf("(from to weight):");
  EDGE *p = g->start;
  while (p)
  {
    printf("(%d %d %d) ", p->from, p->to, p->weight);
    p = p->next;
  }
}