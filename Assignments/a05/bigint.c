#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"
#include "dllist.h"

BIGINT bigint(char *p)
{
    BIGINT bn = {0};
    if (p == NULL)
        return bn;
    else if (!(*p >= '0' && *p <= '9'))
    { // not begin with digits
        return bn;
    }
    else if (*p == '0' && *(p + 1) == '\0')
    { // just "0"
        insert_end(&bn.start, &bn.end, new_node(*p - '0'));
        return bn;
    }
    else
    {
        while (*p)
        {
            if (*p >= '0' && *p <= '9')
            {
                insert_end(&bn.start, &bn.end, new_node(*p - '0'));
            }
            else
            {
                clean_bigint(&bn);
                break;
            }
            p++;
        }
        return bn;
    }
}

void display_bigint(BIGINT bignumber)
{
    NODE *ptr = bignumber.start;
    while (ptr != NULL)
    {
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
}

/*
 *  This cleans the doubly linked list of the big_numberp, which deletes all nodes.
 */
void clean_bigint(BIGINT *bignumberp)
{
    clean(&bignumberp->start, &bignumberp->end);
}

/*
 *  This adds the two BIGINT operants and return the resulted sum BIGINT.
 */
BIGINT add(BIGINT op1, BIGINT op2)
{
    BIGINT sum = bigint(NULL);
    int carry = 0;
    int digit = 0;
    NODE *ptr1 = op1.end;
    NODE *ptr2 = op2.end;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        digit = ptr1->data + ptr2->data + carry;
        carry = digit / 10;
        digit = digit % 10;
        insert_start(&sum.start, &sum.end, new_node(digit));
        ptr1 = ptr1->prev;
        ptr2 = ptr2->prev;
    }
    while (ptr1 != NULL)
    {
        digit = ptr1->data + carry;
        carry = digit / 10;
        digit = digit % 10;
        insert_start(&sum.start, &sum.end, new_node(digit));
        ptr1 = ptr1->prev;
    }
    while (ptr2 != NULL)
    {
        digit = ptr2->data + carry;
        carry = digit / 10;
        digit = digit % 10;
        insert_start(&sum.start, &sum.end, new_node(digit));
        ptr2 = ptr2->prev;
    }
    if (carry != 0)
    {
        insert_start(&sum.start, &sum.end, new_node(carry));
    }
    return sum;
}

/*
 *  This computes nth Fibonacci number F(n) using the above the add function and returns F(n) in BIGINT type
 */
BIGINT Fibonacci(int n)
{
    if (n <= 2)
    {
        return bigint("1");
    }
    else
    {
        BIGINT temp = bigint(NULL);
        BIGINT f1 = bigint("1");
        BIGINT f2 = bigint("1");

        // your implementation of iterative algorithm for Fibonacci number
        for (int i = 3; i <= n; i++)
        {
            temp = add(f1, f2);
            f1 = f2;
            f2 = temp;
        }

        return f2;
    }
}