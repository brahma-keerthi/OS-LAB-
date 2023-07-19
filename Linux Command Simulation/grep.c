#include<stdio.h>
#include<string.h>

void main(){
    FILE *fp;
    char file[10], temp[100], pat[20];

    printf("Enter the file name>> ");
    scanf("%s", file);
    printf("Enter the pattern>> ");
    scanf("%s", pat);

    fp = fopen(file, "r");
    while ( !feof(fp) ){
        fgets(temp, 50, fp);

        if (strstr(temp, pat)) 
            printf("\n%s", pat);
    }
}