#ifndef DLLIST
#define DLLIST

// Define a doubly linked list node structure NODE to hold a character data.
typedef struct NODE
{
    char data;
    struct NODE *next;
    struct NODE *prev;
} NODE;

NODE *new_node(char data);

/*
 * This displays char data from start to end.
 */
void display_forward(NODE *start);

/*
 * This displays char data from end to start.
 */
void display_backward(NODE *end);

/*
 * This inserts a new node at the beginning the of doubly linked list.
 */
void insert_start(NODE **startp, NODE **endp, NODE *new_np);

/*
 * This inserts a new node at the end of the doubly linked list.
 */
void insert_end(NODE **startp, NODE **endp, NODE *new_np);

/*
 * This deletes the first node of the doubly linked list.
 */
void delete_start(NODE **startp, NODE **endp);

/*
 * This deletes the last node of the doubly linked list.
 */
void delete_end(NODE **startp, NODE **endp);

/*
 * This cleans the doubly linked list.
 */
void clean(NODE **startp, NODE **endp);

#endif