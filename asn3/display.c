// Name of the program: display.c
// Program description: outputs the user inputted integer using seven segment displays
// Author: Matvey Skripchenko

#include <stdio.h>
#include <stdlib.h>

// Attribute declaration
int userValue;  // value holding the integer user choice
char userChar;  // value holding the character user choice
int continueExecution = 1; // condition for the do/while execution

// three dimensional array holding characters for the segments
const char segments[10][3][3] = { {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}}, // 0
                                  {{' ', '|', ' '}, {' ', '|', ' '}, {' ', ' ', ' '}}, // 1
                                  {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}}, // 2
                                  {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}}, // 3
                                  {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}}, // 4
                                  {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}}, // 5
                                  {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}}, // 6
                                  {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, // 7
                                  {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}}, // 8
                                  {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}} }; // 9

// three dimensional array holding characters for segments and used for the negative integer user input
const char neg_segments[10][3][4] = { {{' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}, {' ', ' ', ' ', ' '}}, // empty
                                      {{' ', '_', '|', ' '}, {' ', ' ', '|', ' '}, {' ', ' ', ' ', ' '}}, // -1
                                      {{' ', ' ', '_', ' '}, {'_', ' ', '_', '|'}, {' ', '|', '_', ' '}}, // -2
                                      {{' ', ' ', '_', ' '}, {'_', ' ', '_', '|'}, {' ', ' ', '_', '|'}}, // -3
                                      {{' ', ' ', ' ', ' '}, {'_', '|', '_', '|'}, {' ', ' ', ' ', '|'}}, // -4
                                      {{' ', ' ', '_', ' '}, {'_', '|', '_', ' '}, {' ', ' ', '_', '|'}}, // -5
                                      {{' ', ' ', '_', ' '}, {'_', '|', '_', ' '}, {' ', '|', '_', '|'}}, // -6
                                      {{' ', ' ', '_', ' '}, {'_', ' ', ' ', '|'}, {' ', ' ', ' ', '|'}}, // -7
                                      {{' ', ' ', '_', ' '}, {'_', '|', '_', '|'}, {' ', '|', '_', '|'}}, // -8
                                      {{' ', ' ', '_', ' '}, {'_', '|', '_', '|'}, {' ', ' ', '_', '|'}} }; // -9

// main method
int main(void){

    do{
        printf("Please enter the number between -9 and 9 that you want to see as a seven-segment display: ");
        scanf(" %d", &userValue);  // getting the user input as an integer (could be dangerous to do this in other programs)


        if((userValue >= 0)) {
            for(int i = 0; i < 3; i++) {  // cycling through the middle array positions [][i][]
                printf("\n"); // adding newline every time after going through middle array position
                for(int j = 0; j < 3; j++) { // cycling through the last array positions [][][j]

                    printf("%c", segments[userValue][i][j]); // printing the segments
                }
            }


        }else if(userValue < 0) {
            int x = abs(userValue); // converting the negative integer to positive integer

            for (int i = 0; i < 3; i++) { // cycling through the middle array positions [][i][]
                printf("\n"); // adding newline every time after going through middle array position
                for (int j = 0; j < 4; j++) { // cycling through the last array positions [][][j], 4 positions is because pos i = 1 holds the minus sign in j = 0

                    printf("%c", neg_segments[x][i][j]);  // printing the segments
                }
            }
        }

        printf("\n\nPlease enter 'Y' if you want to keep going or 'N' to quit: ");
        scanf(" %c", &userChar); // getting the user input as a character

        if((userChar == 'N') || (userChar == 'n')){
            printf("Thank you and have a good day!");
            continueExecution = 0;  // condition is false, ends the execution
            break;

        }else if((userChar == 'Y') || (userChar == 'y')){
            continueExecution = 1;

        }else{
            printf("Error, please try again!\n");
            continueExecution = 1;
        }



    }
    while(continueExecution == 1);  // do, while the condition is true

}
