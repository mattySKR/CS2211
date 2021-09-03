// Name of program: bstree.c
// Program description: functions for BS tree
// Author: Matvey Skripchenko

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/bstree.h"


// Function allocating memory of type BStree node* and setting the value to NULL
// @param void
// @return a pointer to the allocated memory

BStree bstree_ini(void){

    BStree bst;
    bst = (BStree)malloc(sizeof(BStree_node*)); // allocating memory of type BStree_node*
    *bst = NULL; // setting its value to NULL

    return bst; // pointer to allocated memory is returned
}

// Helper function for bstree_insert creating a pointer to a tree node from key and data
// @param Key key
// @param Data data
// @return a pointer to a tree node from key and data

BStree_node *new_node(Key key, Data data){

    BStree_node *new_node;
    new_node = (BStree_node*)malloc(sizeof(BStree_node)); // allocating memory of type BStree_node

    new_node->key = key; // storing key in the node
    new_node->data = data; // storing data in the node
    new_node->right = NULL; // setting up the right pointer
    new_node->left = NULL; // setting up the left pointer

    return new_node;
}


// Function inserting data with key into bst. If key is in bst, then nothing is done
// @param BStree bst
// @param Key key
// @param Data data

void bstree_insert(BStree bst, Key key, Data data){

    if(*bst == NULL){  // if root is null

        *bst = new_node(key, data); // create new node as a root

    }else{

        if((key_comp(key, (*bst)->key)) > 0){  // if comparison value is greater than 0

            bstree_insert(&(*bst)->right, key, data); // go right

        }else if ((key_comp(key, (*bst)->key)) < 0) {  // if comparison value is less than 0

            bstree_insert(&(*bst)->left, key, data);  // go left

        }  // nothing is done if the key is already in bst
    }
}


// Function returning key’s associated data if key is in bst, otherwise returns NULL
// @param BStree bst
// @param Key key
// @return key’s associated data if key is in bst, otherwise returns NULL

Data bstree_search(BStree bst, Key key){

    BStree_node *new_node = *bst;

    if(*bst == NULL){  // if there is no root

        return NULL;

    }else{

        if(key_comp(key, new_node->key) == 0){ // if the same keys

            return new_node->data;  // returning associated data for that key

        }else if(key_comp(key, new_node->key) > 0){  // if comparison value is greater than 0

            return bstree_search(&new_node->right, key);  // go right recursively

        }else{  // if comparison value is less than 0

            return bstree_search(&new_node->left, key); // go left recursively
        }
    }
}


// Function performing inorder traversal of bst and printing each node’s key and data
// @param BStree bst

void bstree_traversal(BStree bst){

    BStree_node *node = *bst;

    if(node != NULL){  // if not a null node
        bstree_traversal(&node -> left); // go left
        key_print(node->key);  // print node's key
        data_print(node->data); // print node's data
        bstree_traversal(&node->right); // go right
    }
}

// Function freeing all the dynamically allocated memory of bst
// @param BStree bst

void bstree_free(BStree bst){

    data_free((*bst)->data);
    key_free((*bst)->key);
    free((*bst)->left);
    free((*bst)->right);
    free(*bst);
}
