#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(int argc, char * argv[]){
    if (argc == 1){
        printf("No arguments passed");
        exit(0);
    }

    FILE *fp;
    char c;

    fp = fopen(argv[1], "r");

    while((c = fgetc(fp)) != EOF)
        printf("%c", c);

    fclose(fp);
}
