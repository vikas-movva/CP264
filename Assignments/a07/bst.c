#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "bst.h"
/* search bst by data.name */
TNODE *search(TNODE *root, char *name)
{
    if (root == NULL)
        return NULL;
    else if (strcmp(name, root->data.name) == 0)
        return root;
    else if (strcmp(name, root->data.name) < 0)
        return search(root->left, name);
    else
        return search(root->right, name);
}

/* insert record (name, score) into bst using data.name as key */
void insert(TNODE **rootp, char *name, float score)
{
    if (*rootp == NULL)
    {
        *rootp = (TNODE *)malloc(sizeof(TNODE));
        strcpy((*rootp)->data.name, name);
        (*rootp)->data.score = score;
        (*rootp)->left = NULL;
        (*rootp)->right = NULL;
    }
    else if (strcmp(name, (*rootp)->data.name) < 0)
        insert(&(*rootp)->left, name, score);
    else
        insert(&(*rootp)->right, name, score);
}

/* delete node of data.name from bst */
void delete (TNODE **rootp, char *name)
{
    TNODE *temp;
    if (*rootp == NULL)
        return;
    else if (strcmp(name, (*rootp)->data.name) < 0)
        delete (&(*rootp)->left, name);
    else if (strcmp(name, (*rootp)->data.name) > 0)
        delete (&(*rootp)->right, name);
    else
    {
        if ((*rootp)->left == NULL)
        {
            temp = *rootp;
            *rootp = (*rootp)->right;
            free(temp);
        }
        else if ((*rootp)->right == NULL)
        {
            temp = *rootp;
            *rootp = (*rootp)->left;
            free(temp);
        }
        else
        {
            temp = extract_smallest_node(&(*rootp)->right);
            strcpy((*rootp)->data.name, temp->data.name);
            (*rootp)->data.score = temp->data.score;
            free(temp);
        }
    }
}

/* get and return and delete the node of the smallest data.name node from the bst */
TNODE *extract_smallest_node(TNODE **rootp)
{
    TNODE *temp;
    if ((*rootp)->left == NULL)
    {
        temp = *rootp;
        *rootp = (*rootp)->right;
        return temp;
    }
    else
        return extract_smallest_node(&(*rootp)->left);
}

/* display bst tree data by in-order */
void display_inorder(TNODE *root)
{
    if (root)
    {
        if (root->left)
            display_inorder(root->left);
        printf("%-15s%3.1f\n", root->data.name, root->data.score);
        if (root->right)
            display_inorder(root->right);
    }
}

/* clean the tree */
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