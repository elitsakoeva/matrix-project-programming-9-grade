#include "matrix.h"

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