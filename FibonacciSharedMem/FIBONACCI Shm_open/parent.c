#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc, char * argv[]){
    if ( argc < 1){
        printf("No arguments passed !! \n");
        exit(2);
    }

    int shmid, id;
    void * psm;

    shmid = shm_open("OS", O_RDWR, 0666);
    printf("PARENT -- ID of shared memory >> %d\n", shmid);
    ftruncate(shmid, 1024);
    psm = mmap(0, 1024, PROT_WRITE, MAP_SHARED, shmid, 0);

    id = fork();
    if (id == 0){
        // CHILD
        execlp("./fib", "fib", argv[1], NULL);
    }

    else{
        wait(NULL);
        printf("PARENT -- Child finished execution\n");
        printf("PARENT -- Printing Fibonacci >> \n");
        printf("PARENT -- %s\n", (char *)psm);
    }

    shm_unlink("OS");
}