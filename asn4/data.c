// Name of the program: data.c
// Program description: contains functions for keys and node content printing
// Author: Matvey Skripchenko

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"


// Function outputting the pointer of type pointer to Key, pointing to an allocated memory containing a Key
// @param char *in_name
// @param int in_id
// @return pointer of type pointer to Key, pointing to an allocated memory containing a Key

Key *key_construct(char *in_name, int in_id){

    Key *key;
    key = (Key *) (malloc(sizeof(Key)));
    key->name = strdup(in_name); // dynamically allocates the memory for the Key's name so that name will
    key->id = in_id; // holds a Key set Key's id to be in_id
    return key;

}


// Function comparing the parameters key1 and key2
// @param Key key1
// @param Key key2
// @return if return value < 0, then key1 < key2,
//         if return value = 0, then key1 = key2 (only if key1.id == key2.id after key1.name == key2.name was determined to be true),
//         if return value > 0, then key1 > key2.

int key_comp(Key key1, Key key2){

    int ret;

    ret = strcmp(key1.name, key2.name);

    if (ret < 0){  // if key1.name < key2.name
        return ret;

    }else if(ret > 0){ // if key1.name > key2.name
        return ret;

    }else if(key1.id < key2.id) {
        return -1;

    }else if(key1.id > key2.id) {
        return 1;

    }else{
        return ret; // if the names are equals AND the numbers are equals (duplicate keys)
    }
}


// Function printing ( key -> name key -> id )
// @param Key *key

void print_key(Key *key){

    printf("(%-20.20s   %6d)", key -> name, key -> id);

}


// Function printing node.key and then node.data
// @param Node node

void print_node(Node node){

    printf("\t%5.d\n", node.data);

    // !!! I have decided to not print the node.key in this function as I will use print_key function for that purpose

}


