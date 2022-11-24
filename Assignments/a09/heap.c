#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

HEAP *new_heap(int capacity)
{
  HEAP *heap = (HEAP *)malloc(sizeof(HEAP));
  heap->capacity = capacity;
  heap->size = 0;
  heap->hnap = (HNODE *)malloc(sizeof(HNODE) * capacity);
  return heap;
}

void insert(HEAP *heap, HNODE new_node)
{
  if (heap->size == heap->capacity)
  {
    heap->capacity *= 2;
    heap->hnap = (HNODE *)realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
  }
  heap->hnap[heap->size] = new_node;
  heap->size++;
  int i = heap->size - 1;
  while (i > 0 && cmp(heap->hnap[i].key, heap->hnap[(i - 1) / 2].key) < 0)
  {
    HNODE temp = heap->hnap[i];
    heap->hnap[i] = heap->hnap[(i - 1) / 2];
    heap->hnap[(i - 1) / 2] = temp;
    i = (i - 1) / 2;
  }
}

HNODE extract_min(HEAP *heap)
{
  HNODE min = heap->hnap[0];
  heap->hnap[0] = heap->hnap[heap->size - 1];
  heap->size--;
  int i = 0;
  while (i < heap->size)
  {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left >= heap->size)
    {
      break;
    }
    else if (right >= heap->size)
    {
      if (cmp(heap->hnap[i].key, heap->hnap[left].key) > 0)
      {
        HNODE temp = heap->hnap[i];
        heap->hnap[i] = heap->hnap[left];
        heap->hnap[left] = temp;
        i = left;
      }
      else
      {
        break;
      }
    }
    else
    {
      if (cmp(heap->hnap[i].key, heap->hnap[left].key) > 0 && cmp(heap->hnap[i].key, heap->hnap[right].key) > 0)
      {
        if (cmp(heap->hnap[left].key, heap->hnap[right].key) < 0)
        {
          HNODE temp = heap->hnap[i];
          heap->hnap[i] = heap->hnap[left];
          heap->hnap[left] = temp;
          i = left;
        }
        else
        {
          HNODE temp = heap->hnap[i];
          heap->hnap[i] = heap->hnap[right];
          heap->hnap[right] = temp;
          i = right;
        }
      }
      else if (cmp(heap->hnap[i].key, heap->hnap[left].key) > 0)
      {
        HNODE temp = heap->hnap[i];
        heap->hnap[i] = heap->hnap[left];
        heap->hnap[left] = temp;
        i = left;
      }
      else if (cmp(heap->hnap[i].key, heap->hnap[right].key) > 0)
      {
        HNODE temp = heap->hnap[i];
        heap->hnap[i] = heap->hnap[right];
        heap->hnap[right] = temp;
        i = right;
      }
      else
      {
        break;
      }
    }
  }
  // resize heap and copy data if necessary
  if (heap->size < heap->capacity / 2)
  {
    heap->capacity /= 2;
    heap->hnap = (HNODE *)realloc(heap->hnap, sizeof(HNODE) * heap->capacity);
  }

}

void decrease_key(HEAP *heap, int node_index, KEYTYPE key_value)
{
  heap->hnap[node_index].key = key_value;
  int i = node_index;
  while (i > 0 && cmp(heap->hnap[i].key, heap->hnap[(i - 1) / 2].key) < 0)
  {
    HNODE temp = heap->hnap[i];
    heap->hnap[i] = heap->hnap[(i - 1) / 2];
    heap->hnap[(i - 1) / 2] = temp;
    i = (i - 1) / 2;
  }
}

int find_index(HEAP *heap, DATA value)
{
  for (int i = 0; i < heap->size; i++)
  {
    if (heap->hnap[i].data == value)
    {
      return i;
    }
  }
  return -1;
}

void display_heap(HEAP *hp)
{
  printf("\nsize:%d\ncapacity:%d\n", hp->size, hp->capacity);
  printf("(index, key, data): ");
  int i;
  for (i = 0; i < hp->size; i++)
  {
    printf("(%d %d %d) ", i, hp->hnap[i].key, hp->hnap[i].data);
    if (i % 10 == 9)
      printf("\n");
  }
  printf("\n");
}

int cmp(KEYTYPE a, KEYTYPE b)
{
  if (a < b)
    return -1;
  else if (a == b)
    return 0;
  else
    return 1;
}
