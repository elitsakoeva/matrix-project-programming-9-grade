#include "matrix.h" 

void matrix_substraction(FUNCTION_PARAMETERS) {
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            RES[i][j] = A[i][j] - B[i][j];
        }
    }
}