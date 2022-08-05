#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>

void main(int argc, char * argv[]){
    int id, shmid;
    void * psm;

    if ( argc < 1){
        printf("No arguments passsed!!! \n");
        exit(1);
    }

    shmid = shmget((key_t)1122, 1024, 0666|IPC_CREAT);
    printf("ID of shared memory >> %d\n", shmid);
    psm = shmat(shmid, NULL, 0666);
    printf("Process attached at > %p\n", psm);

    id = fork();

    if ( id == 0 ){
        // CHILD called
        execlp("./fib", "fib", argv[1], NULL);
    }
    else{
        // PARENT
        wait(NULL);
        printf("PARENT -- Child completed execution\n");
        printf("PARENT -- Priting fibonacci >> \n");
        printf("PARENT -- %s \n", (char *)psm);
        shmdt(psm);
    }
}