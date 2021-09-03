// Name of the program: main.c
// Program description: inserts the user inputted values into the tree and shows the final result tree
// Author: Matvey Skripchenko

#include <stdio.h>
#include "bst.h"

int main(void) {

    // Attribute declaration
    BStree bst;
    int keep_going = 1;
    char q;
    char string[150];
    int user_id;
    int user_data;
    int size;

    printf("\nPlease enter the size of the tree you would like to use:\n"); // prompting the user for an input
    scanf("%d", &size); // getting the input from the user

    bst = bstree_ini(size); // creating an empty tree of the specified size

    do{

        printf("\nPlease enter the key & id & data with a whitespace in between of each value:\n");

        if(scanf("%s %d %d", string, &user_id, &user_data) == 3){ // checking if user input is a triple
            bstree_insert(bst, key_construct(string, user_id), user_data); // inserting the triple with the user values into the tree
            keep_going = 1;

            printf("\nPlease enter 'q' to quit the program and see the final result or 'c' to input more values:\n");
            scanf(" %c", &q);

            if(q == 'Q' || q == 'q') {
                keep_going = 0;
                break;

            }else if(q == 'c' || q == 'C'){
                keep_going = 1;

            }else{
                printf("\nInvalid input, please try again!\n");
                keep_going = 0;
                break;
            }

        }


    } while(keep_going);

    bstree_traversal(bst); // traversing bst
    bstree_free(bst); // freeing all the memory used by bst
}

