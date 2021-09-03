// Name of the program: pi.c
// Program description: approximating mathematical constant pi based on the user entered small (double precision) number epsilon.
// Author: Matvey Skripchenko

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void) {

    // Attribute declaration
    int keep_going = 1;
    char q;
    double n = 1, epsilon, final, sum = 0.0;

    double new_sum = 0.0;

    // Prompting the user for input
    printf("Please enter the tolerance:\n");

    scanf("%lf", &epsilon);  // getting the user input

    do{

        sum = new_sum + (pow(-1, n + 1) * (4 / ((2 * n) - 1.0)));  // series sum for a given n

        if((4 / (2 * (n + 1) - 1)) < epsilon){ // tolerance condition

            keep_going = 0;
            break;
        }

        n = n + 1; // next member of series
        new_sum = sum;


    }while(keep_going);

    final = sum;

    printf("\nThe approximate value of the mathematical constant pi for tolerance (epsilon) %.12f is %2.25lf\n", epsilon, final);

}



