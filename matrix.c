#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define MAX_MATRICES 10

extern Matrix matrices[MAX_MATRICES];
extern int matrix_count;

int main(void) {

    int choice = 0;

    while(1){
        print_menu();

        do{
            printf("Enter your choice (1 - 5). \n");
            scanf("%d", &choice);
        } while(choice < 1 || choice > 5);

        if (choice == 1){
            Matrix m;
            create_matrix(&m);
            add_matrix_to_arr(&m);
        }

        else if (choice == 2){
            display_matrices();
        }

        else if(choice == 3){
            if(matrix_count == 0) {
                printf("No matrices to delete. Go and add some. \n");
                return;
            }

            int index;
            do{
                printf("Enter matrix number (the matrix will be deleted): \n");
                scanf("%d", &index);
            }while(index < 0 || index > matrix_count);

            delete_matrix(index-1);
        }

        else if(choice == 4){
             
            if(matrix_count == 0) {
                printf("Enter a matrix/matrices first. \n");
                continue;
            }

            print_options();

            int m1, m2;
            Matrix res;

            int option;
            do{
                printf("Choose an option: \n");
                scanf("%d", &option);
            } while(option < 1 || option > 5);
            

            if(option == 1) {
                display_matrices();

                do{
                    printf("Enter matrix 1: \n");
                    scanf("%d", &m1);
                }while(m1 < 1 || m1 > matrix_count);

                do{
                    printf("Enter matrix 2: \n");
                    scanf("%d", &m2);
                }while(m2 < 1 || m2 > matrix_count);

                if(matrices[m1 - 1].rows != matrices[m2 - 1].rows || matrices[m1 - 1].columns != matrices[m2 -1].columns){
                    printf("Matrices must have the same size for addition. ( YxZ + YxZ = YxZ)\n");
                    continue;
                }

                matrix_addition(&matrices[m1 - 1], &matrices[m2 - 1], &res);
                print_matrix(&res);

            }

            else if(option == 2){
                display_matrices();

                do{
                    printf("Enter matrix 1: \n");
                    scanf("%d", &m1);
                }while(m1 < 1 || m1 > matrix_count);

                do{
                    printf("Enter matrix 2: \n");
                    scanf("%d", &m2);
                }while(m2 < 1 || m2 > matrix_count);

                if(matrices[m1 - 1].rows != matrices[m2 - 1].rows || matrices[m1 - 1].columns != matrices[m2 -1].columns){
                    printf("Matrices must have the same size for subtraction. ( YxZ - YxZ = YxZ)\n");
                    continue;
                }

                matrix_subtraction(&matrices[m1 - 1], &matrices[m2 - 1], &res);
                print_matrix(&res);
            }

            else if(option == 3){
                display_matrices();

                do{
                    printf("Enter matrix 1: \n");
                    scanf("%d", &m1);
                }while(m1 < 1 || m1 > matrix_count);

                do{
                    printf("Enter matrix 2: \n");
                    scanf("%d", &m2);
                }while(m2 < 1 || m2 > matrix_count);

                if(matrices[m1 - 1].columns != matrices[m2 - 1].rows) {
                    printf("Matrix 1's columns must equal to Matrix 2's rows. \n");
                    continue;
                }

                matrix_multiplication(&matrices[m1 - 1], &matrices[m2 - 1], &res);
                print_matrix(&res);
            }

            else if(option == 4){
                display_matrices();

                do{
                    printf("Enter matrix 1: \n");
                    scanf("%d", &m1);
                }while(m1 < 1 || m1 > matrix_count);

                matrix_transpose(&matrices[m1 - 1], &res);
                print_matrix(&res);
            }

            else{
                printf("You're being redirected to the basic menu. \n");
                continue;
            }
        }

        else {
            printf("Program exited. \n");
            break;
        }
        
    }


    
    return 0;
}