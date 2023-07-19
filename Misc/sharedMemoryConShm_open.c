#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>

void main(){
    int shmid;
    void * psm;

    shmid = shm_open("OS", O_RDONLY, 0666);
    ftruncate(shmid, 1024);
    printf("ID of shared memory >> %d\n", shmid);

    psm = mmap(0, 1024, PROT_READ, MAP_SHARED, shmid, 0);
    printf("Shared memory attached to >> %p\n", psm);
    printf("Data in shared memory >> %s\n", (char *)psm);
    shm_unlink(psm);
}