// Name of the program: bst.h
// Program description: header for bst.c
// Author: Matvey Skripchenko

#ifndef ASSIGNMENT_4_BST_H
#define ASSIGNMENT_4_BST_H

#endif //ASSIGNMENT_4_BST_H
#include "data.h"

typedef struct {Node *tree_nodes; unsigned char *is_free; int size;}BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, int data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void recursive_insertion(BStree bst, Key *key, int data, int i);
void recursive_traversal(BStree bst, int i);



