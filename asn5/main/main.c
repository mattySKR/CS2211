#include <stdio.h>
#include "../include/matrix.h"


int main(void){

// Attribute declaration

    int keep_going = 1;
    char q;
    char user_string1[150];
    char user_string2[150];
    int user_id;
    int user_data;

    Matrix user_matrix = matrix_construction();  // creating a new matrix

    do{

        printf("\nPlease enter a pair of strings separated by whitespace:\n");

        if(scanf("%s %s", user_string1, user_string2) == 2){ // checking if user input is a string pair
            matrix_set(user_matrix, user_string1, user_string2, 1);
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

    } while(keep_going); // execute while true

    matrix_list(user_matrix);  // displaying the contents of the matrix

    matrix_destruction(user_matrix);  // freeing the memory

}
