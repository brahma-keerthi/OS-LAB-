#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main(int argc, char * argv[]){
    int shmid;
    void * psm;
    int n, i = 2, n1, n2, n3;

    shmid = shm_open("OS", O_CREAT|O_RDWR, 0666);
    ftruncate(shmid, 1024);
    printf("CHILD -- ID of shared memory >> %d\n", shmid);
    psm = mmap(0, 1024, PROT_WRITE, MAP_SHARED, shmid, 0);

    n = atoi(argv[1]);
    printf("CHILD -- Printing fibonacci nubmers >> \n");
    n1 = 0;
    sprintf(psm, "%d ", n1);
    psm += strlen(psm);
    printf("CHILD -- %d ", n1);

    n2 = 1;
    sprintf(psm, "%d ", n2);
    psm += strlen(psm);
    printf("%d ", n2);

    while ( i<n ){
        n3 = n1 + n2;
        sprintf(psm , "%d ", n3);
        psm += strlen(psm);
        printf("%d ", n3);
        n1 = n2;
        n2 = n3;
        ++i;
    }
    printf("\n");
}