#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>
#include<string.h>

void main(int argc, char * argv[]){
    int shmid;
    void * psm;
    int m, n, flag;
    m = atoi(argv[1]);
    n = atoi(argv[2]);

    shmid = shm_open("OS", O_RDWR, 0666 );
    ftruncate(shmid , 1024);
    printf("CHILD -- ID of shared memory >> %d\n", shmid);
    psm = mmap(0, 1024, PROT_WRITE, MAP_SHARED, shmid, 0);
    printf("CHILD -- Prime numbers in given range >> \n");
    printf("CHILD -- ");

    for(int i = m; i<=n; ++i){
        flag = 0;
        for(int j = 2; j<=i/2; ++j){
            if ( i%j == 0 ){
                flag = 1;
                break;
            }
        }

        if (flag == 0){
            printf("%d ", i);
            sprintf(psm, "%d ", i);
            psm += strlen(psm);
        } 
    }
    printf("\n\n");
}