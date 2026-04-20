#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define ASSERT_TEST(MESSAGE, CONDITION) \
    if(CONDITION) { \
        printf(MESSAGE ":PASSED \n"); \
    } else { \
        printf(MESSAGE ":FAILED\n"); \
    }

extern Matrix * matrices;
extern int matrix_count;

Matrix A, B, C;

void defined_matrices(){

    A.rows = 2;
    A.columns = 3;
    allocate_dmem_for_res(&A, A.rows, A.columns);

    B.rows = 2;
    B.columns = 3;
    allocate_dmem_for_res(&B, B.rows, B.columns);

    C.rows = 3;
    C.columns = 2;
    allocate_dmem_for_res(&C, C.rows, C.columns);

    int arr[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int arr2[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };

    for(int i = 0; i<2; i++) {
        for(int j = 0; j<3; j++) {
            A.matrix[i][j] = arr[i][j];
        }
    }

    for(int i = 0; i<2; i++) {
        for(int j = 0; j<3; j++) {
            B.matrix[i][j] = arr[i][j];
        }
    }

    for(int i = 0; i<3; i++) {
        for(int j = 0; j<2; j++) {
            C.matrix[i][j] = arr2[i][j];
        }
    }
}

void test_addition() {
    Matrix RES;
    matrix_addition(&A, &B, &RES);

    ASSERT_TEST("Addition is working: ",
        RES.matrix[0][0] == 2 &&
        RES.matrix[0][1] == 4 &&
        RES.matrix[0][2] == 6 &&
        RES.matrix[1][0] == 8 &&
        RES.matrix[1][1] == 10 &&
        RES.matrix[1][2] == 12
    );

    free_matrix(&RES);
}

void test_subtraction() {
    Matrix RES;
    matrix_subtraction(&A, &B, &RES);

    ASSERT_TEST("Subtraction is working: ",
        RES.matrix[0][0] == 0 &&
        RES.matrix[0][1] == 0 &&
        RES.matrix[0][2] == 0 &&
        RES.matrix[1][0] == 0 &&
        RES.matrix[1][1] == 0 &&
        RES.matrix[1][2] == 0
    );

    free_matrix(&RES);
}

void test_multiplication() {
    Matrix RES;
    matrix_multiplication(&A, &C, &RES);

    ASSERT_TEST("Multiplication is working: ",
        RES.matrix[0][0] == 22 &&   
        RES.matrix[0][1] == 28 &&
        RES.matrix[1][0] == 49 &&
        RES.matrix[1][1] == 64
    );

    free_matrix(&RES);

}

void test_transpose() {
    Matrix RES;
    matrix_transpose(&A, &RES);

    ASSERT_TEST("Transpose is working: ",
        RES.matrix[0][0] == 1 &&
        RES.matrix[1][0] == 2 &&
        RES.matrix[2][0] == 3 &&
        RES.matrix[0][1] == 4 &&
        RES.matrix[1][1] == 5 &&
        RES.matrix[2][1] == 6
    );

    free_matrix(&RES);
}

void test_add_matrix_to_arr() {
    free_all_matrices();

    add_matrix_to_arr(&A);
    ASSERT_TEST("Matrix 1 should be matrix A and the count should be 1: ", 
        matrix_count == 1 && 
        matrices[0].matrix[0][0] == 1 &&
        matrices[0].matrix[0][1] == 2 &&
        matrices[0].matrix[0][2] == 3 &&
        matrices[0].matrix[1][0] == 4 &&
        matrices[0].matrix[1][1] == 5 &&
        matrices[0].matrix[1][2] == 6
    );

}

void test_delete_matrix() {
    free_all_matrices();

    add_matrix_to_arr(&A);
    add_matrix_to_arr(&C);

    delete_matrix(0);

    ASSERT_TEST("Matrix 1 should be matrix C and the count should be 1: ", 
        matrix_count == 1 && 
        matrices[0].matrix[0][0] == 1 &&
        matrices[0].matrix[0][1] == 2 &&
        matrices[0].matrix[1][0] == 3 &&
        matrices[0].matrix[1][1] == 4 &&
        matrices[0].matrix[2][0] == 5 &&
        matrices[0].matrix[2][1] == 6
    );

}

int main(void) {
    defined_matrices();

    test_addition();
    test_subtraction();
    test_multiplication();
    test_transpose();
    
    test_add_matrix_to_arr();
    test_delete_matrix();

    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);
    
    free_all_matrices();

    return 0;
}