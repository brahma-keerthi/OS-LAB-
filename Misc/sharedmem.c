#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<unistd.h>
#include<sys/shm.h>

void main(){
    void * psm;
    char buffer[10];
    int shmid;

    shmid = shmget((key_t)1122, 1024, 0666|IPC_CREAT);
    printf("Key of shared memory >> %d\n",shmid);
    psm = shmat(shmid, NULL, 0666);
    
    printf("Address of shared memory >> %p\n", psm);

    // printf("Enter data to shared memory>> ");
    fflush(stdin);
    read(0, buffer, 10);
    sprintf(psm, "%s", buffer);

    shmdt(psm);
}

// shmget -> unique key, size of bytes, permission and to create returns shmid
// shmat -> shmid , NULL, permission
// sprintf -> shared mem add, data