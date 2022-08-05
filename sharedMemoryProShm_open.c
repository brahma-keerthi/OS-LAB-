#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/mman.h>
#include<fcntl.h>

void main(){
    int shmid;
    void * psm;
    char buffer[10];

    shmid = shm_open("OS", O_CREAT | O_RDWR, 0666);
    ftruncate(shmid, 1024);
    printf("ID of shared memory >> %d\n", shmid);
    psm = mmap(0, 1024, PROT_WRITE, MAP_SHARED, shmid, 0);
    printf("Shared memory attached at >> %p\n", psm);
    printf("Enter data for shared memory >> ");
    scanf("%s", buffer);
    sprintf(psm, "%s", buffer);
}

// shm_open -> identifier, open method, permissipon -> returns shmid
// ftruncate -> extends the size to parameter -> shmid, size
// mmap -> 0, size, method to open file, map_shared, shmid, 0