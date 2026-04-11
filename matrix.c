#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int main(void) {

    int choice = 0;

    while(1){
        print_menu();

        do{
            printf("Enter your choice (1 - 5). \n");
            scanf("%d", &choice);
        } while(choice < 1 || choice > 4);

        if (choice == 1){
            // дава опция на потребителя да въведе нова матрица
        }

        else if (choice == 2){
            // принтират се всички записани матрици
        }

        else if(choice == 3){
            // трие се матрица по избор на потребителя (може би по име или номер?)
        }

        else if(choice == 4){
            // показва се ново меню с операции
        }

        else {
            // прекратява програмата
        }
        
    }



    return 0;
}