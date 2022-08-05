#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

void main(int argc, char * argv []){
    if (argc < 2){
        printf("No arguments passed >@\n");
        exit(2);
    }

    if ( argv[1]> argv[2]){
        printf("Invalid arguments !#@\n");
        exit(2);
    }

    int id, shmid;
    void * psm;

    shmid = shm_open("OS", O_CREAT | O_RDWR, 0666);
    ftruncate(shmid, 1024);
    printf("PARENT -- ID of shared memory >> %d\n", shmid);
    psm = mmap(0, 1024, PROT_READ, MAP_SHARED, shmid, 0);

    id = fork();

    if ( id == 0 ){
        //cHILD
        execlp("./prime", "prime", argv[1], argv[2], NULL);
    }

    else{
        wait(NULL);
        printf("PARENT -- Child finished execution\n");
        printf("PARENT -- Printing fibonacci numbers>> \n");
        printf("PARENT -- %s \n", (char *)psm);
    }
    shm_unlink("OS");
}