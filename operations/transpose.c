#include "matrix.h"

void matrix_transpose(FUNCTION_PARAMETERS_TRANSPOSE){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            RES[j][i] = A[i][j];
        }
    }
}