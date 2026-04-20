#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix * matrices = NULL;
int matrix_count = 0;

void print_menu() {
    printf("\n ============= MENU: ============= \n");
    printf("1. New matrix. \n");
    printf("2. Display existing matrices. \n");
    printf("3. Delete a matrix. \n");
    printf("4. Do an operation with matrix/matrices. \n");
    printf("5. Exit. \n");
    printf("\n ================================= \n");
}

void create_matrix(Matrix * matrix){
    do{
        printf("Enter rows: \n");
        scanf("%d", &matrix->rows);
    } while(matrix->rows < 1);

    do{
        printf("Enter columns: \n");
        scanf("%d", &matrix->columns);
    } while(matrix->columns < 1);

    matrix->matrix = malloc(matrix->rows * sizeof(int *));
    if(matrix->matrix == NULL) {
        printf("Error allocating memory. \n");
        exit(1);
    }

    for(int i=0; i < matrix->rows; i++){
        matrix->matrix[i] = malloc(matrix->columns * sizeof(int));
        if(matrix->matrix[i] == NULL) {
            printf("Error allocating memory. \n");
            exit(1);
        }
    }

    printf("Enter the values in a matrix: \n");
    for(int i=0; i<matrix->rows; i++){
        for(int j=0; j<matrix->columns; j++){
            scanf("%d", &matrix->matrix[i][j]);
        }
    }

}

void add_matrix_to_arr(Matrix * matrix) {
    
    Matrix * temp = realloc(matrices, (matrix_count + 1) * sizeof(Matrix));
    if(temp== NULL) {
        printf("Error reallocating memory.\n");
        exit(1);
    }
    matrices = temp;

    matrices[matrix_count].rows = matrix->rows;
    matrices[matrix_count].columns = matrix->columns;

    matrices[matrix_count].matrix = malloc(matrix->rows * sizeof(int *));
    if(matrices[matrix_count].matrix == NULL) {
        printf("Error allocating memory. \n");
        exit(1);
    }

    for(int i=0; i < matrix->rows; i++) {
        matrices[matrix_count].matrix[i] = malloc(matrix->columns * sizeof(int));
        if(matrices[matrix_count].matrix[i] == NULL) {
            printf("Error allocating memory. \n");
            exit(1);
        }
    }

    for(int i=0; i< matrix->rows; i++) {
        for(int j = 0; j< matrix->columns; j++) {
            matrices[matrix_count].matrix[i][j] = matrix->matrix[i][j];
        }
    }

    matrix_count++;
}

void display_matrices() {
    if(matrix_count == 0){
        printf("No matrices. \n");
        return;
    }

    for(int i=0; i<matrix_count; i++){
        printf("\n Matrix %d \n", i+1);
        print_matrix(&matrices[i]);
    }
}

void delete_matrix(int index){
    if(index < 0 || index >= matrix_count){
        printf("Invalid index. \n");
        return;
    }

    free_matrix(&matrices[index]);

    for(int i=index; i<matrix_count - 1; i++){
        matrices[i] = matrices[i+1];
    }

    matrix_count--;

    matrices = realloc(matrices, matrix_count * sizeof(Matrix));

    printf("Matrix deleted. \n");

}


void print_matrix(Matrix * matrix) {
    for(int i = 0; i < matrix->rows; i++) {
        for(int j = 0; j < matrix->columns; j++)
            printf("%d ", matrix->matrix[i][j]);
        printf("\n");
    }
    printf("\n");
}

void free_matrix(Matrix * matrix) {
    for(int i=0; i<matrix->rows; i++) {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
}

void free_all_matrices() {
    for(int i=0; i < matrix_count; i++) {
        free_matrix(&matrices[i]);
    }

    free(matrices);
    matrices = NULL;
    
    matrix_count = 0;
}