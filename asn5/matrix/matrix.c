// Name of the program: matrix.c
// Program description: functions for the matrix implemented using BStree
// Author: Matvey Skripchenko

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/matrix.h"


// Function constructing the matrix using bstree_ini()
// @param void
// @return matrix implemented by bstree_ini()

Matrix matrix_construction(void){

    Matrix mtrx = bstree_ini();  // constructing the matrix using bst

    return mtrx;
}


// Function returning 1 if the location (index1, index2) is defined in Matrix m, otherwise returns 0
// @param Matrix m
// @param Index index1
// @param Index index2
// @return 1 if the location (index1, index2) is defined in Matrix m, return 0 otherwise

unsigned char matrix_isin(Matrix m, Index index1, Index index2){

    Key key = key_gen(index1, index2);  // generating the key with indexes

    if(bstree_search(m, key) == NULL){  // if the location (index1, index2) is not defined in the Matrix m

        return 0;

    }else{ // if the location (index1, index2) is defined in the Matrix m

        return 1;
    }
}


// Function returning a pointer to the associated value if the location (index1, index2) is defined in Matrix m, otherwise returns NULL
// @param Matrix m
// @param Index index1
// @param Index index2
// @return a pointer to the associated value if the location (index1, index2) is defined in Matrix m, returns NULL otherwise

Value *matrix_get(Matrix m, Index index1, Index index2){

    Key key = key_gen(index1, index2); // generating the key with indexes

    if((matrix_isin(m, index1, index2)) == 0){  // if the location (index1, index2) is not defined in the Matrix m

        return NULL;

    }else{  // if the location (index1, index2) is defined in the Matrix m

        return bstree_search(m, key);  // returning the pointer to the associated value
    }
}


// Function assigning value to Matrix m at location (index1, index2). Overwrites the location if it already has value
// @param Matrix m
// @param Index index1
// @param Index index2
// @param Value value

void matrix_set(Matrix m, Index index1, Index index2, Value value){

    Value *target = matrix_get(m, index1, index2);  // assigning value to Matrix m

    if(target == NULL){  // if that location does not have a value

        Key key = key_gen(index1, index2);  // generating the key with indexes

        Value *val = data_gen(value); // generating data
        bstree_insert(m, key, val);  // inserting with the new value

    }else{  // if the location already has value

        matrix_inc(m, index1, index2, value);  // overwriting
    }
}


// Function increasing the associated value by value if the location (index1, index2) is defined in Matrix m, otherwise reports an error
// @param Matrix m
// @param Index index1
// @param Index index2
// @param Value value

void matrix_inc(Matrix m, Index index1, Index index2, Value value){

    Value *target = matrix_get(m, index1, index2);

    if(target != NULL){  // if location (index1, index2) is defined in Matrix m

        (*target)++;  // incrementing

    }else{  // outputting error, otherwise

        printf("Error: location (index1, index2) is not defined in Matrix m \n");
    }
}


// Function printing indices and values in the Matrix m using previously created bstree_traversal() function
// @param Matrix m

void matrix_list(Matrix m){

    printf("\n%-15s  %-15s  %-15s\n\n", "String 1", "String 2", "Occurrence");
    bstree_traversal(m);
}


// Function freeing allocated space using previously created bstree_free() function
// @param Matrix m

void matrix_destruction(Matrix m){

    bstree_free(m);
}
