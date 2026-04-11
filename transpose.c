#include "matrix.h"

void matrix_transpose(FUNCTION_PARAMETERS_TRANSPOSE){
    RES->rows = A->columns;
    RES->columns = A->rows;

    for(int i=0; i<A->rows; i++){
        for(int j=0; j<A->columns; j++){
            RES->matrix[j][i] = A->matrix[i][j];
        }
    }
}