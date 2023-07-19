#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<fcntl.h>

void main(){
    void * psm;
    int shmid;
    char buffer[10];

    shmid = shmget((key_t)1122, 1024, 0666);
    printf("ID of shared memory >> %d\n", shmid);

    psm = shmat(shmid, NULL, 0666);
    printf("Process attached at >> %p\n", psm);
    printf("Data in shared mem >> %s", (char *)psm);

    shmctl(shmid, IPC_RMID, NULL);
}

// shmctl -> destroys the shared memory