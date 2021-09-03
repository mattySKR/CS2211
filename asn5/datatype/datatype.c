// Name of program: datatype.c
// Program description: functions for data and key manipulations
// Author: Matvey Skripchenko

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/datatype.h"


// Function duplicating the string pointed to by str with dynamic memory allocation
// @param char *str
// @return duplicate string pointed to by str with dynamic memory allocation

char * string_dup(char *str){

    char *key_duplicate;
    key_duplicate = (char*) malloc(sizeof(char) * strlen(str) + 1); // allocating memory of type char
    strcpy(key_duplicate, str); // copying one string to another

    return key_duplicate;
}


// Function generating a key with dynamic memory allocation
// @param char *skey1
// @param char *skey2
// @return a key with dynamic memory allocation

Key key_gen(char *skey1, char *skey2){

    Key key;
    key = (Key_struct*)malloc(sizeof(Key_struct)); // allocating memory of type Key_struct

    // initializing skey1 and skey2 for the key by using the already created string duplicate function
    key->skey1 = string_dup(skey1);
    key->skey2 = string_dup(skey2);

    return key;
}


// Function comparing the keys using strcmp() function
// @param Key key1
// @param Key key2
// @return comparison result based on strcmp(), which is an integer

int key_comp(Key key1, Key key2) {

    int comparison = strcmp(key1->skey1, key2->skey1);

    if (comparison != 0) { // if key1->skey1 and key1->skey1 are different

        return comparison;

    } else {  // if key1->skey1 and key1->skey1 are the same

        return strcmp(key1->skey2, key2->skey2); // result judged by the comparison of key1->skey2 and key2->skey2
    }

}


// Function printing a key
// @param Key key

void key_print(Key key){

    printf("%-15s  %-15s", key -> skey1, key -> skey2);

}


// Function freeing the memory allocated for the key
// @param Key key

void key_free(Key key){

    free(key -> skey1);
    free(key -> skey2);
}


// Function generating data with dynamic memory allocation
// @param int idata
// @return data with dynamic memory allocation

Data data_gen(int idata){

    Data data;
    data = (int*)malloc(sizeof(Data)); // allocating memory of type Data
    data_set(data,idata);  // assigning data with idata

    return data;
}


// Function assigning data with data
// @param Data data
// @param int idata
// @return idata assigned with data

void data_set(Data data, int idata){

    *data = idata;
}


// Function printing data
// @param Data data

void data_print(Data data){

    printf("  %d\n", *data);
}


// Function freeing the memory allocated for data
// @param Data data

void data_free(Data data){

    free(data);
}

