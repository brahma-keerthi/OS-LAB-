#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>

void main(int argc, char * argv[]){
    int i = 2, n1, n2, n3;
    n1 = 0; n2 = 1;
    int shmid;
    void * psm;

    shmid = shmget((key_t)1122, 1024, 0666);
    printf("ID of shared mem >> %d\n", shmid);
    psm = shmat(shmid, NULL, 0666);

    int n = atoi(argv[1]);
    sprintf(psm, "%d ", n1);
    printf("CHILD -- Printing Fibo >> \n");
    printf("CHILD -- %d ", n1);
    psm += strlen(psm);
    sprintf(psm, "%d ", n2);
    printf("%d ", n2);
    psm += strlen(psm);

    while ( i < n ){
        n3 = n2 + n1;
        sprintf(psm, "%d ", n3);
        printf("%d ", n3);
        psm += strlen(psm);

        n1 = n2;
        n2 = n3;
        ++i;
    }
    printf("\n");
    shmctl(shmid, IPC_RMID, NULL);
}