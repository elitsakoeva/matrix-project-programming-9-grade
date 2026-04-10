#include <stdio.h>
#include "matrix.h"

#define ROWS 3
#define COLUMNS 3

void print_matrix(int rows, int columns, int A[rows][columns]) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main(void) {

    int A[ROWS][COLUMNS] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[ROWS][COLUMNS] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int RES[ROWS][COLUMNS];

    matrix_addition(ROWS, COLUMNS, A, B, RES);
    print_matrix(ROWS, COLUMNS, RES);

    matrix_substraction(ROWS, COLUMNS, A, B, RES);
    print_matrix(ROWS, COLUMNS, RES);

    matrix_multiplication(ROWS, COLUMNS, A, B, RES);
    print_matrix(ROWS, COLUMNS, RES);

    matrix_transpose(ROWS, COLUMNS, A, RES);
    print_matrix(COLUMNS, ROWS, RES);

    return 0;
}