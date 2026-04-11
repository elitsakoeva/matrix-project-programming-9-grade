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