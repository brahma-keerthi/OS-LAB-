#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void main(){
    int id = fork();
    if (id < -1){
        printf("Failed to create child");
        exit(1);
    }

    if ( id == 0 ){
        // CHILD PROCESS
        printf("CHILD -- My pid is %d\n", getpid());
        printf("CHILD -- My parent pid is %d\n", getppid());
        printf("CHILD -- Exiting to be a ZOMBIE\n");
        exit(0);
    }

    else{
        // PARENT PROCESS
        printf("PARENT -- My pid is %d\n", getpid());
        printf("PARENT -- My parent pid is %d\n", getppid());
        printf("PARENT -- I am sleeping now that is I would not be able to reap of my CHILD\n");
        // Sleep at the time of returning of the exit status of child
        sleep(10);
        printf("PARENT -- I did not get exit status of CHILD\n");
        printf("PARENT -- My entry in PROCESS TABLE is present is called ZOMBIE PROCESS\n");
    }
}