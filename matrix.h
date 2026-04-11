#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MAX_SIZE 10

typedef struct {
    int rows;
    int columns;
    int matrix[MAX_SIZE][MAX_SIZE];
} Matrix;

#define FUNCTION_PARAMETERS Matrix * A, Matrix * B, Matrix * RES
#define FUNCTION_PARAMETERS_TRANSPOSE Matrix * A, Matrix * RES

void print_menu();
void print_options();

void create_matrix(Matrix * matrix);

void matrix_addition(FUNCTION_PARAMETERS);
void matrix_subtraction(FUNCTION_PARAMETERS);
void matrix_multiplication(FUNCTION_PARAMETERS);
void matrix_transpose(FUNCTION_PARAMETERS_TRANSPOSE);

void print_matrix(Matrix * matrix);

#endif