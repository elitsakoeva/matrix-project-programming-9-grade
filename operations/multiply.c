#include "matrix.h"

void matrix_multiplication(FUNCTION_PARAMETERS){
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            RES[i][j] = 0;
            for(int z=0; z<columns; z++){
                RES[i][j] += A[i][j] * B[i][j];
            }
        }
    }
}