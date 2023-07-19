#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

void main(int argc, char * argv []){
    int shmid, i = 0;
    void * psm;
    int n = atoi(argv[1]);

    shmid = shmget((key_t)1122, 1024, 0666);
    printf("CHILD -- Key of shared memory>> %d\n", shmid);
    psm = shmat(shmid, NULL, 0666);

    printf("CHILD -- Printing Fibonacci >> \n");
    printf("CHILD -- ");
    while ( i< n){
        sprintf(psm , "%d ", i*2 + 1);
        printf("%d ", i*2 + 1);
        psm += strlen(psm);
        ++i;
    }
    printf("\n\n");
    shmctl(shmid, IPC_RMID, NULL);
}