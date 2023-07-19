#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>

void main(int argc, char *argv[]){
    if ( argc < 1){
        printf("No arguments passed..!!\n");
        exit(1);
    }

    void * psm;
    int id, shmid;

    shmid = shmget((key_t)1122, 1024, 0666|IPC_CREAT);
    printf("PARENT -- Key of shared memory >> %d\n", shmid);
    psm = shmat(shmid, NULL, 0666);

    id = fork();

    if (id == 0){
        execlp("./odd", "odd", argv[1], NULL);
    }

    else{
        wait(NULL);
        printf("PARENT -- Child finished execution\n");
        printf("PARENT -- Printing fibonacci numbers >> \n");
        printf("PARENT -- %s \n", (char *) psm);
    }
    shmdt(psm);
}