#include<stdio.h>
#include<stdlib.h>

void main(int argv, char * argc[]){
    if (argv == 1){
        printf("No arguments passed");
        exit(0);
    }

    int flag = remove(argc[1]);
    // flag = 0 Sucess removal
    // flag = -1 failure

    if (flag == 0)
        printf("%s removed successfully", argc[1]);
    else
        printf("%s cant be removed", argc[1]);
}