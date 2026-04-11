#include <stdio.h>
#include "matrix.h"

#define ROWS 3
#define COLUMNS 3

void print_matrix(Matrix * matrix) {
    for(int i = 0; i < matrix->rows; i++) {
        for(int j = 0; j < matrix->columns; j++)
            printf("%d ", matrix->matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void test_number_one(){
    Matrix A = {
       ROWS,
       COLUMNS,
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    };


    Matrix B = {
       ROWS,
       COLUMNS,
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    };
    
    Matrix RES;

    matrix_addition(&A, &B, &RES);
    print_matrix(&RES);

    matrix_subtraction(&A, &B, &RES);
    print_matrix(&RES);

    matrix_multiplication(&A, &B, &RES);
    print_matrix(&RES);

    matrix_transpose(&A, &RES);
    print_matrix(&RES);

}

int main(void) {

    test_number_one();

    return 0;
}