#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

void main(int argc, char * argv[]){
    if ( argc < 2) {
        printf("No arguments passed\n");
        exit(0);
    }

    DIR *dp;
    struct dirent * dirc;

    dp = opendir(argv[1]);

    while ( (dirc = readdir(dp)) != NULL )
        printf("%s\n", dirc->d_name);
}