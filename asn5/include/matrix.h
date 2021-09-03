// Name of the program: matrix.h
// Program description: header file for matrix.c
// Author: Matvey Skripchenko

#ifndef ASSIGNMENT5_MATRIX_H
#define ASSIGNMENT5_MATRIX_H
#endif //ASSIGNMENT5_MATRIX_H
#include "bstree.h"

typedef BStree Matrix;
typedef char* Index;
typedef int Value;
Matrix matrix_construction(void);
unsigned char matrix_isin(Matrix m, Index index1, Index index2);
Value *matrix_get(Matrix m, Index index1, Index index2);
void matrix_set(Matrix m, Index index1, Index index2, Value value);
void matrix_inc(Matrix m, Index index1, Index index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);
