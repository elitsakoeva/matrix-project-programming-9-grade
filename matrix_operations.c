#include <stdio.h>
#include "matrix.h"

void print_options() {
    printf("\n ============= OPTIONS: ============= \n");
    printf("1. Add (+) (matrix1 + matrix2). \n");
    printf("2. Subtract (-) (matrix1 - matrix2). \n");
    printf("3. Dot product (*) (matrix1 * matrix2) (also known as multiplying). \n");
    printf("4. Transpose (T) ( (matrix1)T ) (swapping rows and columns in a matrix). \n");
    printf("5. Exit to previous menu. \n");
    printf("\n ================================= \n");
}

void matrix_addition(FUNCTION_PARAMETERS){
    RES->rows = A->rows;
    RES->columns = A->columns;

    for(int i=0; i<A->rows; i++){
        for(int j=0; j<A->columns; j++){
            RES->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
    }
}

void matrix_subtraction(FUNCTION_PARAMETERS) {
    RES->rows = A->rows;
    RES->columns = A->columns;

    for(int i=0; i<A->rows; i++){
        for(int j=0; j<A->columns; j++){
            RES->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
    }
}

void matrix_multiplication(FUNCTION_PARAMETERS){
    RES->rows = A->rows;
    RES->columns = B->columns;

    for(int i=0; i<A->rows; i++){
        for(int j=0; j<B->columns; j++){
            RES->matrix[i][j] = 0;
            for(int z=0; z<A->columns; z++){
                RES->matrix[i][j] += A->matrix[i][z] * B->matrix[z][j];
            }
        }
    }
}

void matrix_transpose(FUNCTION_PARAMETERS_TRANSPOSE){
    RES->rows = A->columns;
    RES->columns = A->rows;

    for(int i=0; i<A->rows; i++){
        for(int j=0; j<A->columns; j++){
            RES->matrix[j][i] = A->matrix[i][j];
        }
    }
}