#include<stdio.h>
#include<stdlib.h>

void main(int argc, char* argv[]){
    printf("Process name>> %s", argv[0]);

    if (argc == 1){
        printf("No command line arguments passed");
    }
    else if (argc >=2){
        for(int i = 0; i<argc; i++)
            printf("Argument %d >> %s\n",i+1, argv[i]);
    }
}

// C program to illustrate
// command line arguments
// #include<stdio.h>

// int main(int argc,char* argv[])
// {
// 	int counter;
// 	printf("Program Name Is: %s",argv[0]);
// 	if(argc==1)
// 		printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
// 	if(argc>=2)
// 	{
// 		printf("\nNumber Of Arguments Passed: %d",argc);
// 		printf("\n----Following Are The Command Line Arguments Passed----");
// 		for(counter=0;counter<argc;counter++)
// 			printf("\nargv[%d]: %s",counter,argv[counter]);
// 	}
// 	return 0;
// }
