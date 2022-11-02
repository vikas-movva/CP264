#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression.h"

/*
 * auxiliary function
 */
int get_priority(char op)
{
    if (op == '/' || op == '*' || op == '%')
        return 1;
    else if (op == '+' || op == '-')
        return 0;
    else
        return -1;
}

/*
 * auxiliary function
 */
int type(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    else if (c == '/' || c == '*' || c == '%' || c == '+' || c == '-')
        return 1;
    else if (c == '(')
        return 2;
    else if (c == ')')
        return 3;
    else
        return 4;
}

/*
 * convert infix expression in string to postfix expression represented by QUEUE and return the postfix expression queue.
 */
QUEUE infix_to_postfix(char *infix)
{
    QUEUE postfix = {0};
    STACK op_stack = {0};
    NODE *np;
    char *p = infix;
    int num = 0;
    int sign = 1;
    while (*p != '\0')
    {
        if (*p == '-' && (p == infix || *(p - 1) == '(')) // get sign
        {
            sign = -1;
        }
        else if (type(*p) == 0) // is number
        {
            num = *p - '0';
            while (type(*(p + 1)) == 0)
            {
                num = num * 10 + *(p + 1) - '0';
                p++;
            }
            np = new_node(sign * num, 0);
            enqueue(&postfix, np);
        }
        else if (type(*p) == 1) // is operator
        {
            while (op_stack.top != NULL && get_priority(op_stack.top->data) >= get_priority(*p))
            {
                np = pop(&op_stack);
                np->next = NULL;
                enqueue(&postfix, np);
            }
            np = new_node(*p, 1);
            push(&op_stack, np);
        }
        else if (type(*p) == 2)
        {
            np = new_node(*p, 2);
            push(&op_stack, np);
        }
        else if (type(*p) == 3)
        {
            while (op_stack.top->data != '(')
            {
                np = pop(&op_stack);
                np->next = NULL;
                enqueue(&postfix, np);
            }
            np = pop(&op_stack);
        }
        p++;
    }
    while (op_stack.top != NULL)
    {
        np = pop(&op_stack);
        enqueue(&postfix, np);
    }
    return postfix;
}

/*
 * evaluate and returns the value postfix expression passed by queue.
 */
int evaluate_postfix(QUEUE queue)
{
    STACK num_stack = {0};
    NODE *np;
    int num1, num2;
    while (queue.front != NULL)
    {
        np = dequeue(&queue);
        if (np->type == 0)
        {
            push(&num_stack, np);
        }
        else if (np->type == 1)
        {
            num2 = pop(&num_stack)->data;
            num1 = pop(&num_stack)->data;
            if (np->data == '+')
                np->data = num1 + num2;
            else if (np->data == '-')
                np->data = num1 - num2;
            else if (np->data == '*')
                np->data = num1 * num2;
            else if (np->data == '/')
                np->data = num1 / num2;
            else if (np->data == '%')
                np->data = num1 % num2;
            np->type = 0;
            push(&num_stack, np);
        }
    }
    return pop(&num_stack)->data;
}

/*
 * evaluate and return the value of prefix expression passed by string infixstr, using infix_to_postfix() and evaluate_postfix() functions.
 */
int evaluate_prefix(char *infixstr)
{
    QUEUE postfix = infix_to_postfix(infixstr);
    return evaluate_postfix(postfix);
    clean_queue(&postfix);
}