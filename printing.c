#include <stdio.h>
#include "matrix.h"

void print_menu() {
    printf("\n ============= MENU: ============= \n");
    printf("1. New matrix. \n");
    printf("2. Display existing matrices. \n");
    printf("3. Delete a matrix. \n");
    printf("4. Do an operation with matrix/matrices. \n");
    printf("5. Exit. \n");
    printf("\n ================================= \n");
}


void print_options() {
    printf("\n ============= OPTIONS: ============= \n");
    printf("1. Add (+) (matrix1 + matrix2). \n");
    printf("2. Subtract (-) (matrix1 - matrix2). \n");
    printf("3. Dot product (*) (matrix1 * matrix2) (also known as multiplying). \n");
    printf("4. Transpose (T) ( (matrix1)T ) (swapping rows and columns in a matrix). \n");
    printf("5. Exit to previous menu. \n");
    printf("\n ================================= \n");
}


void print_matrix(Matrix * matrix) {
    for(int i = 0; i < matrix->rows; i++) {
        for(int j = 0; j < matrix->columns; j++)
            printf("%d ", matrix->matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}
