#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression_symbol.h"

QUEUE infix_to_postfix_symbol(char *infixstr, HASHTABLE *ht)
{
  QUEUE q = {0};
  STACK s = {0};
  int i = 0;
  while (infixstr[i] != '\0')
  {
    if (infixstr[i] == ' ')
    {
      i++;
      continue;
    }
    if (infixstr[i] >= '0' && infixstr[i] <= '9')
    {
      int num = 0;
      while (infixstr[i] >= '0' && infixstr[i] <= '9')
      {
        num = num * 10 + (infixstr[i] - '0');
        i++;
      }
      enqueue(&q, new_node(num, 0));
    }
    else if (infixstr[i] == '(')
    {
      push(&s, new_node(infixstr[i], 1));
      i++;
    }
    else if (infixstr[i] == ')')
    {
      while (s.top->data != '(')
      {
        enqueue(&q, pop(&s));
      }
      pop(&s);
      i++;
    }
    else if (infixstr[i] == '+' || infixstr[i] == '-' || infixstr[i] == '*' || infixstr[i] == '/')
    {
      while (s.top != NULL && s.top->data != '(') 
      {
        enqueue(&q, pop(&s));
      }
      push(&s, new_node(infixstr[i], 1));
      i++;
    }
    else
    {
      char symbol[10];
      int j = 0;
      while (infixstr[i] >= 'a' && infixstr[i] <= 'z')
      {
        symbol[j] = infixstr[i];
        i++;
        j++;
      }
      symbol[j] = '\0';
      int value = search(ht, symbol)->value;
      enqueue(&q, new_node(value, 0));
    }
  }
  while (s.top != NULL)
  {
    enqueue(&q, pop(&s));
  }
  return q;
}

int evaluate_infix_symbol(char *infixstr, HASHTABLE *ht)
{
  QUEUE q = infix_to_postfix_symbol(infixstr, ht);
  return evaluate_postfix(q);
}

int evaluate_postfix(QUEUE queue)
{
  STACK s = {0};
  while (queue.front != NULL)
  {
    NODE *np = dequeue(&queue);
    if (np->type == 0)
    {
      push(&s, np);
    }
    else
    {
      int num1 = pop(&s)->data;
      int num2 = pop(&s)->data;
      int result = 0;
      if (np->data == '+')
      {
        result = num2 + num1;
      }
      else if (np->data == '-')
      {
        result = num2 - num1;
      }
      else if (np->data == '*')
      {
        result = num2 * num1;
      }
      else if (np->data == '/')
      {
        result = num2 / num1;
      }
      push(&s, new_node(result, 0));
    }
  }
  return pop(&s)->data;
}

// you can use this function in your program
int resolve_symbol(char *statement, HASHTABLE *ht)
{
  char name[10] = {0};
  char *dest = strstr(statement, "=");
  if (dest)
    *dest = '\0';
  else
    dest = statement;
  strcpy(name, statement);

  if ((name[0] >= 'a' && name[0] <= 'z') || (name[0] >= 'A' && name[0] <= 'Z'))
  {

    int value = evaluate_infix_symbol(dest + 1, ht);

    if (value == 99999) // escape value
      return 2;
    else
    {
      insert(ht, new_hashnode(name, value));
    }
    return 1;
  }
  return 0;
}