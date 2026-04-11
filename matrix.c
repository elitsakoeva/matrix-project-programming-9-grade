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
            // показва се ново меню с операции 
            print_options();
            // ...............

        }

        else {
            printf("Program exited. \n");
            break;
        }
        
    }



    return 0;
}