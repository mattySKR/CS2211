// Name of program: bst.c
// Program description: functions for BS tree
// Author: Matvey Skripchenko

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Function dynamically allocating the memory of type BStree_struct type,
// dynamically allocating the memory for a Node array of size+1 for member tree_nodes,
//  allocating the memory for an unsigned char array of size+1 for member is_free,
// setting all entries of is_free to 1 and setting member size to 'size'.
// @param int size
// @return a pointer to an allocated memory of BStree_struct type

BStree bstree_ini(int size){


    BStree bst;
    bst = (BStree_struct*) (malloc(sizeof(BStree_struct))); // allocating memory of type BStree_struct
    bst -> tree_nodes = (Node*) (malloc((size + 1) * sizeof(Node))); // allocating memory for a Node array of size+1 for member tree_nodes
    bst -> is_free = (unsigned char*) (malloc((size + 1) * sizeof(unsigned char))); // allocating memory for an unsigned char array of size+1 for member is_free

    for(int i = 0; i <= size; i++){ // setting all entries of is_free to '1'

        bst -> is_free[i] = '1';
    }
    bst -> size = size; // setting member size to size
    return bst;
}


// Function inserting 'data' with 'key' into 'bst'
// @param BStree bst
// @param Key *key
// @param int data

void bstree_insert(BStree bst, Key *key, int data){

    recursive_insertion(bst, key, data, 1);

}


// Helper function doing the recursive search in the array for the first empty position
// @param BStree tree
// @param Key *key
// @param char name
// @parm int data
// @param int i

void recursive_insertion(BStree bst, Key *key, int data, int i){

    if(i > bst -> size){  // if index out of bounds

        printf("Error: array index out of bounds!\n");

    }else if(bst -> is_free[i] == '1'){ // if root

        if((bst -> tree_nodes[i].key = key) == '\0'){ // if the key has nothing
            printf("Error: the node cannot be created!\n");
        }
        bst -> tree_nodes[i].key = key_construct(key -> name, key -> id); // inserting the key with name and id into the node
        bst -> tree_nodes[i].data = data; // inserting data into the node
        bst -> is_free[i] = '0'; // entry occupied

    }else{

        if(key_comp(*key, *(bst -> tree_nodes[i].key)) == 0){ // if the both key's contents are the same

            printf("\nThe key (%s  %d) is already in the array!!! Insertion omitted.\n\n", key -> name, key -> id);

        }else if(key_comp(*key, *(bst -> tree_nodes[i].key)) > 0){ // if key1 > key2

            recursive_insertion(bst, key, data, (i * 2) + 1); // insert the right child

        }else{ // if key1 < key2

            recursive_insertion(bst, key, data, (i * 2)); // insert the left child

        }

    }

}


// Function printing all the nodes in bst using in order traversal
// @param BStree bst

void bstree_traversal(BStree bst){

    recursive_traversal(bst, 1);

}

// Helper function doing in order recursive traversal
// @param BStree bst
// @param int i

void recursive_traversal(BStree bst, int i){

    if(bst -> is_free[i] == '0'){ // if the current position is occupied

        recursive_traversal(bst, (i * 2)); // visit left child

        print_key(bst -> tree_nodes[i].key);
        // visit root
        print_node(bst -> tree_nodes[i]);

        recursive_traversal(bst, ((i * 2) + 1)); // visit right child

    }

}

// Function freeing all the memory used by bst
// @param BStree bst
void bstree_free(BStree bst){

    free(bst -> tree_nodes);
    free(bst -> is_free);
    free(bst);

}



