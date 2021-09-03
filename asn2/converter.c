// Name of the program: converter.c
// Program description: converts between the units based on the choice of the user
// Author: Matvey Skripchenko

#include <stdio.h>

int main(void)
{

    char conversionChoice, unitChoice;  // User's choice of what they want the conversion unit/choice to be
    float km, mile, meter, feet, cm, inch, celsius, fahrenheit; // Conversion units for user to choose from
    int continueExecution = 101;  // Condition for the while statement that will return the user back to the choice options after the conversion or any other operation was processed

    // km <-> conversion scale factors
    #define MILE_SCALE_FACTOR 0.621371f
    #define KM_SCALE_FACTOR 1.60934f

    // meter <-> feet conversion scale factors
    #define METER_SCALE_FACTOR 0.3048f
    #define FEET_SCALE_FACTOR 3.28084f

    // cm <-> inch conversion scale factors
    #define CM_SCALE_FACTOR 2.54f
    #define INCH_SCALE_FACTOR 0.393701f

    // Celsius <-> Fahrenheit conversion scale factors and freezing point
    #define FREEZING_POINT 32.0F
    #define FAHRENHEIT_SCALE_FACTOR (9.0f / 5.0f)
    #define CELSIUS_SCALE_FACTOR (5.0f / 9.0f)


    do {

        printf("\nPlease choose the conversion units:  ");
        printf("\n 1 [kilometer <-> mile]");
        printf("\n 2 [meter <-> feet]");
        printf("\n 3 [centimeter <-> inch]");
        printf("\n 4 [Celsius <-> Fahrenheit]");
        printf("\n 5 [quit program]\n");

        scanf(" %c", &conversionChoice); // This will let the user create the input

        switch(conversionChoice) { // Here, based on the user input, the program will jump into 1 of the 5 options chosen by the user

            case '1': // kilometer <-> mile conversion

                printf("Enter 'K' for kilometer -> mile conversion or 'M' for mile -> kilometer conversion.\n");
                scanf(" %c", &unitChoice);

                if (unitChoice == 'K' || unitChoice == 'k') { // Handles both uppercase and lowercase user input
                    printf("Please enter the distance(km):\n");
                    scanf("%f", &km);
                    mile = (km * MILE_SCALE_FACTOR);
                    printf("Result: the conversion of %.2f kilometers to miles is %.2f miles.\n", km, mile);
                    continueExecution = 101;

                } else if (unitChoice == 'M' || unitChoice == 'm') { // Handles both uppercase and lowercase user input
                    printf("Please enter the distance(mile):\n");
                    scanf("%f", &mile);
                    km = (mile * KM_SCALE_FACTOR);
                    printf("Result: the conversion of %.2f miles to kilometers is %.2f kilometers.\n", mile, km);
                    continueExecution = 101;
                } else {
                    printf("Result: your input is invalid, please try again.\n");
                }
                continueExecution = 101;

                break; // ends the process, the condition of the while loop is then checked in order to return back to the main menu (conversion options)

            case '2': // meter <-> feet conversion

                printf("Enter 'M' for meter -> feet conversion or 'F' for feet -> meter conversion.\n");
                scanf(" %c", &unitChoice);

                if (unitChoice == 'M' || unitChoice == 'm') { // Handles both uppercase and lowercase user input
                    printf("Please enter the distance(meter):\n");
                    scanf("%f", &meter);
                    feet = (meter * FEET_SCALE_FACTOR);
                    printf("Result: the conversion of %.2f meters to feet is %.2f feet.\n", meter, feet);
                    continueExecution = 101;

                } else if (unitChoice == 'F' || unitChoice == 'f') { // Handles both uppercase and lowercase user input
                    printf("Please enter the distance(feet):\n");
                    scanf("%f", &feet);
                    meter = (feet * METER_SCALE_FACTOR);
                    printf("Result: the conversion of %.2f feet to meters is %.2f meters.\n", feet, meter);
                    continueExecution = 101;

                } else {
                    printf("Result: your input is invalid, please try again.\n");
                }
                continueExecution = 101;

                break;

            case '3': // centimeter <-> inch conversion

                printf("Enter 'C' for centimeter -> inch conversion or 'I' for inches -> feet conversion.\n");
                scanf(" %c", &unitChoice);

                if (unitChoice == 'C' || unitChoice == 'c') { // Handles both uppercase and lowercase user input
                    printf("Please enter the distance(cm):\n");
                    scanf("%f", &cm);
                    inch = (cm * INCH_SCALE_FACTOR);
                    printf("Result: the conversion of %.2f centimeters to inches is %.2f inches.\n", cm, inch);
                    continueExecution = 101;

                } else if (unitChoice == 'I' || unitChoice == 'i') { // Handles both uppercase and lowercase user input
                    printf("Please enter the distance(inches):\n");
                    scanf("%f", &inch);
                    cm = (inch * CM_SCALE_FACTOR);
                    printf("Result: the conversion of %.2f inches to centimeters is %.2f centimeters.\n", inch, cm);
                    continueExecution = 101;

                } else {
                    printf("Result: your input is invalid, please try again.\n");
                }
                continueExecution = 101;

                break;

            case '4': // Celsius <-> Fahrenheit conversion

                printf("Enter 'C' for Celsius -> Fahrenheit conversion or 'F' for Fahrenheit -> Celsius conversion.\n");
                scanf(" %c", &unitChoice);

                if (unitChoice == 'C' || unitChoice == 'c') { // Handles both uppercase and lowercase user input
                    printf("Please enter the temperature(Celsius):\n");
                    scanf("%f", &celsius);
                    fahrenheit = (celsius * FAHRENHEIT_SCALE_FACTOR) + FREEZING_POINT;
                    printf("Result: the conversion of %.2f Celsius to Fahrenheit is %.2f Fahrenheit.\n", celsius,
                           fahrenheit);
                    continueExecution = 101;

                } else if (unitChoice == 'F' || unitChoice == 'f') { // Handles both uppercase and lowercase user input
                    printf("Please enter the temperature(Fahrenheit):\n");
                    scanf("%f", &fahrenheit);
                    celsius = (fahrenheit - FREEZING_POINT) * CELSIUS_SCALE_FACTOR;
                    printf("Result: the conversion of %.2f Fahrenheit to Celsius is %.2f Celsius.\n", fahrenheit, celsius);
                    continueExecution = 101;

                } else {
                    printf("Result: your input is invalid, please try again.\n");
                }
                continueExecution = 101;

                break;

            case '5': // If option '5' was chosen by the user, it will quit the program because the condition of the while loop will be false based on the continueExecution int value

                printf("Thank you for using the converter. Have a good day!\n");
                continueExecution = 1;
                break;

            default: // default setting that handles the case when the user does not choose 1 out 5 given options/cases
                printf("Result: your input is invalid as there is no such options.\n");
                continueExecution = 101;
                break;

        }

    }
    while (continueExecution == 101); // evaluates the condition at least once after the statements have been executed and returns the user back to the main menu (conversion options)
}
