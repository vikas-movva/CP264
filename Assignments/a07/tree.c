#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* this computes and returns TPROPS value containing the number of nodes and height
 * of tree passed by root.
 */
TPROPS get_props(TNODE *root)
{
  TPROPS props;
  if (root == NULL)
  {
    props.height = 0;
    props.count = 0;
  }
  else
  {
    TPROPS left = get_props(root->left);
    TPROPS right = get_props(root->right);
    props.height = 1 + (left.height > right.height ? left.height : right.height);
    props.count = 1 + left.count + right.count;
  }
  return props;
}

/* this displays the node data of the tree by pre-order. */
void display_preorder(TNODE *root)
{
  if (root != NULL)
  {
    printf("%c ", root->data);
    display_preorder(root->left);
    display_preorder(root->right);
  }
}

/* this displays the node data of the tree by in-order. */
void display_inorder(TNODE *root)
{
  if (root)
  {
    if (root->left)
      display_inorder(root->left);
    printf("%c ", root->data);
    if (root->right)
      display_inorder(root->right);
  }
}

/* this displays the node data of the tree by post-order. */
void display_postorder(TNODE *root)
{
  if (root != NULL)
  {
    display_postorder(root->left);
    display_postorder(root->right);
    printf("%c ", root->data);
  }
}

/* this does the breadth-first search */
TNODE *iterative_bf_search(TNODE *root, int val)
{
  QUEUE *queue = (QUEUE *)malloc(sizeof(QUEUE));
  TNODE *node = root;
  while (node != NULL)
  {
    if (node->data == val)
    {
      return node;
    }
    if (node->left != NULL)
    {
      enqueue(queue, node->left);
    }
    if (node->right != NULL)
    {
      enqueue(queue, node->right);
    }
    node = dequeue(queue);
  }
  return NULL;
}

/* this does the depth-first search */
TNODE *iterative_df_search(TNODE *root, int val)
{
  STACK *stack = {0};
  TNODE *node = root;
  while (node != NULL)
  {
    if (node->data == val)
    {
      return node;
    }
    if (node->right != NULL)
    {
      push(stack, node->right);
    }
    if (node->left != NULL)
    {
      push(stack, node->left);
    }
    node = peek(stack);
    pop(stack);
  }
  return NULL;
}

/* basic functions */
TNODE *new_node(int value)
{
  TNODE *np = (TNODE *)malloc(sizeof(TNODE));
  if (np == NULL)
    return NULL;
  np->data = value;
  np->left = NULL;
  np->right = NULL;
  return np;
}

void display_tree(TNODE *root, int prelen)
{
  if (root)
  {
    int i;
    for (i = 0; i < prelen; i++)
      printf("%c", ' ');
    printf("%s", "|___");
    printf("%c\n", root->data);
    display_tree(root->right, prelen + 4);
    display_tree(root->left, prelen + 4);
  }
}

void clean_tree(TNODE **rootp)
{
  TNODE *root = *rootp;
  if (root)
  {
    if (root->left)
      clean_tree(&root->left);
    if (root->right)
      clean_tree(&root->right);
    free(root);
  }
  *rootp = NULL;
}

// queue functions adapted and modified from a6
void enqueue(QUEUE *qp, void *data)
{
  QNODE *p = (QNODE *)malloc(sizeof(QNODE));
  if (p == NULL)
    return;
  else
  {
    p->data = data;
    p->next = NULL;

    if (qp->front == NULL)
    {
      qp->front = p;
      qp->rear = p;
    }
    else
    {
      (qp->rear)->next = p;
      qp->rear = p;
    }
  }
}
void *dequeue(QUEUE *qp)
{
  void *temp = NULL;
  if (qp->front)
  {
    QNODE *p = qp->front;
    temp = p->data;
    if (qp->front == qp->rear)
    {
      qp->front = NULL;
      qp->rear = NULL;
    }
    else
    {
      qp->front = p->next;
    }
    free(p);
    return temp;
  }
  return NULL;
}
void clean_queue(QUEUE *qp)
{
  QNODE *temp, *p = qp->front;
  while (p != NULL)
  {
    temp = p;
    p = p->next;
    free(temp);
  }
}

// stack functions adapted and modified from a6
void push(STACK *sp, void *data)
{
  SNODE *p = (SNODE *)malloc(sizeof(SNODE));
  p->data = data;
  p->next = NULL;
  if (sp->top == NULL)
  {
    sp->top = p;
  }
  else
  {
    p->next = sp->top;
    sp->top = p;
  }
}
void pop(STACK *sp)
{
  if (sp->top != NULL)
  {
    SNODE *p = sp->top;
    sp->top = p->next;
    free(p);
  }
}
void *peek(STACK *sp)
{
  if (sp->top != NULL)
  {
    return sp->top->data;
  }
  return NULL;
}
void clean_stack(STACK *sp)
{
  SNODE *temp, *p = sp->top;
  while (p)
  {
    temp = p;
    p = p->next;
    free(temp);
  }
  sp->top = NULL;
}