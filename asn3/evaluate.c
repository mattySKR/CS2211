// Name of the program: evaluate.c
// Program description: calculates the arithmetic expression given by the user
// Author: Matvey Skripchenko

#include <stdio.h>
#include <stdlib.h>

//Attribute declaration
float m_exp(float sub_exp, char op); // function for m_expression
float s_exp(float sub_exp, char op); // function for s_expression
char get_op(); // function for getting the character
float get_num(); // function for getting the number
char opChar; // character variable holding the operation character
float numChar; // float variable holding the floats
char addit = '+';
char subtr = '-';
char mult = '*';
char divis = '/';
char endLine = '\n';
char space = ' ';
int continueExecution = 1; // condition for do/while execution
char userValue; // variable used for holding the user input


int main(void){

    do{

        printf("Please enter the simple arithmetic expression: ");

        float temp;
        if((temp = getc(stdin)) != EOF){ // going past the first position (0) and getting the input from stdin
            ungetc(temp,stdin);  // throwing fist position back into stdin
        }

        printf("The result of your expression is: %.4f\n", s_exp(get_num(), get_op()));  // printing result

        printf("Please enter 'Y' if you want to evaluate another arithmetic expression or 'N' to quit: ");
        scanf("%c", &userValue); // getting the character value from the user

        if((userValue == 'N') || (userValue == 'n')){
            printf("Thank you for using the arithmetic expression calculator, have a good day!");
            continueExecution = 0;  // condition is false, ends execution
            break;

        }else if((userValue == 'Y') || (userValue == 'y')){
            continueExecution = 1;

        }else{
            printf("There is an error, please try again!\n");
            continueExecution =1;
        }

    }
    while(continueExecution == 1); // do, while the condition is true

}


float get_num(){ //function getting the numeric value from the arithmetic expression

    scanf("%f", &numChar); // getting the floats
    return numChar;

}

char get_op(){  //function getting the operator from the arithmetic expression

    scanf("%c", &opChar);  // getting the operator characters

    if(opChar == addit){ // if op is addition
        return opChar;

    }else if(opChar == subtr){ // if op is subtraction
        return opChar;

    }else if(opChar == mult){ // if op is multiplication
        return opChar;

    }else if(opChar == divis) { // if op is division
        return opChar;

    }else if(opChar == endLine) { // if op is end line character (\n)
        return endLine;

    }else if(opChar == space){ // if op is space
        return get_op();
    }else{
        printf("Error, please try again!\n");
        exit(EXIT_FAILURE);  // if neither, end execution
    }

}

// @param float sub_exp holding the result of uninterrupted division and subtractions
// @param char op holding the operator character
float m_exp(float sub_exp, char op){  //function returning the value of the current m_expression

    if(op == addit) { // if op is addition
        ungetc(op, stdin); // throw it back to stdin
        return sub_exp;

    }else if(op == subtr) { // if op is subtraction
        ungetc(op, stdin); // throw it back to stdin
        return sub_exp;

    }else if(op == endLine) { // if op is end line character (\n)
        ungetc(op, stdin); // throw it back to stdin
        return sub_exp;
    }


    if((op == divis) || (op == mult)){ // if op is either division or multiplication
        float f1 = get_num(); // get next number of the expression
        char c1 = get_op(); // get next op of the expression

        if(op == mult){ // if op is multiplication
            sub_exp = (sub_exp * f1); // multiply next number by previous sub_exp and store the result is new sub_exp

        }else if(op == divis){ // if op is division
            sub_exp = (sub_exp / f1); // divide sub_exp by the next number and store the result is new sub_exp

        }
        return m_exp(sub_exp, c1);  // recursion call m_exp() until the character is +, - or \n. If so, returns sub_exp (aka m_expression)

    }

}

// @param float sub_exp holding the final result of the arithmetic expression (when fully executed)
// @param char op holding the operator character
float s_exp(float sub_exp, char op){ //function returning the value of s_expression

    if(op == endLine){ // if op is end line (\n)
        return sub_exp;  // returns the final expression (aka s_expression) stored in sub_exp

    }else{
        float g = m_exp(sub_exp, op); // get the number using m_exp() recursive call
        char o = get_op(); // get the next op of the expression

        if (o == endLine) {  // if the next op of the expression is end line (\n)
            return g; // return the result determined by m_exp() recursive call

        }else if(o == addit){ // if op is addition
            return (g + s_exp(get_num(), get_op())); // adds the result of m_exp to recursive call s_exp() with new/next sub_exp and op (num1 l_op num2)

        }else if(o == subtr){ // if op is subtraction
            return (g - s_exp(get_num(), get_op()));  // subtracts the s_exp() with new/next sub_exp and op from the result of m_exp() (num1 l_op num2)
        }

    }

}