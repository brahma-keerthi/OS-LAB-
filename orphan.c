#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void main(){
    int id;
    id = fork();
    if (id < 0){
        printf("Failded to create child process");
        exit(0);
    }

    if (id == 0){
        // Child process
        printf("CHILD -- My pid is %d\n", getpid());
        printf("CHILD -- My parent pid is %d\n", getppid());
        printf("CHILD -- I want to become orphan. So I will sleep till parent terminates\n");
        sleep(10);
        printf("CHILD -- My parent terminate so I am ORPHAN and I will be adopted by init process\n");
    }

    else{
        // Parent process
        printf("PARENT -- My pid is %d\n", getpid());
        printf("PARENT -- My parent pid is %d\n", getppid());
        printf("PARENT -- I did not get my child's exit status and I am terminating\n");
        exit(0);
    }
}