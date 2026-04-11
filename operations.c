#include "matrix.h"

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