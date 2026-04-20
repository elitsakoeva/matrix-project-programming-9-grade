#ifndef _MATRIX_H_
#define _MATRIX_H_

typedef struct {
    int rows;
    int columns;
    int ** matrix;
} Matrix;

#define FUNCTION_PARAMETERS Matrix * A, Matrix * B, Matrix * RES
#define FUNCTION_PARAMETERS_TRANSPOSE Matrix * A, Matrix * RES

void print_menu();
void print_options();

void create_matrix(Matrix * matrix);
void add_matrix_to_arr(Matrix * matrix);
void display_matrices();
void delete_matrix(int index);

void free_matrix(Matrix * matrix);
void free_all_matrices();

void allocate_dmem_for_res(Matrix * res, int rows, int columns);
void matrix_addition(FUNCTION_PARAMETERS);
void matrix_subtraction(FUNCTION_PARAMETERS);
void matrix_multiplication(FUNCTION_PARAMETERS);
void matrix_transpose(FUNCTION_PARAMETERS_TRANSPOSE);

void print_matrix(Matrix * matrix);

#endif