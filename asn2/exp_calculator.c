// Name of the program: exp_calculator.c
// Program description: the program will calculate the exponent based on the user's base and exponent inputs
// Author: Matvey Skripchenko

#include <stdio.h>

float result_recursive(float base, int exponent); // recursive function used to calculate the exponent based on the user's inputs

int main(void) {

    float base;
    int exponent;

    printf("Please enter the base number:\n");
    scanf(" %f", &base);  // Asks the user for the base value
    printf("Please enter the exponent number:\n");
    scanf(" %d", &exponent);  // Asks the user for the exponent value


    if((base > 0) && (exponent > 0)){  // Checks if the base and the exponent are positive
        float result = result_recursive(base, exponent);
        printf("Your result for the base %.3f and the exponent %d is %.3f\n", base, exponent, result);
        return 0;  //successfully ends the program

    } else if((base > 0) && (exponent < 0)){ // Checks if the base is positive and the exponent is negative
        float result = result_recursive(base, exponent);
        float inverse = (1.0f / result); // So for the case when the user chooses a negative exponent, the answer will just be the inverse of the result
        printf("Your result for the base %.3f and the exponent %d is %.3f\n", base, exponent, inverse);
        return 0;

    } else {
        printf("Your input is invalid, please try again. Possible solution: base must be positive\n");
        return 0;
    }

}

    float result_recursive(float base, int exponent){  // Recursive function that produces the desired result

        if(exponent > 0){  // If the user decided to use a negative exponent
            return result_recursive(base, exponent -1) * base;
        }

        if(exponent < 0){  // If the user decided to use a positive exponent
            return result_recursive(base, exponent + 1) * base;

        } else {  // If the exponent is neither positive nor negative, therefore equal to zero
            return 1;
        }
    }

