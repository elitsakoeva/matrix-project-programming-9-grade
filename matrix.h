#ifndef _MATRIX_H_
#define _MATRIX_H_

#define FUNCTION_PARAMETERS int rows, int columns, int A[rows][columns], int B[rows][columns], int RES[rows][columns]
#define FUNCTION_PARAMETERS_TRANSPOSE int rows, int columns, int A[rows][columns], int RES[columns][rows]

void matrix_addition(FUNCTION_PARAMETERS);
void matrix_substraction(FUNCTION_PARAMETERS);
void matrix_multiplication(FUNCTION_PARAMETERS);
void matrix_transpose(FUNCTION_PARAMETERS_TRANSPOSE);

#endif