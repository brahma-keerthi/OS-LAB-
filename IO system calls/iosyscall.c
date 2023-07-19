#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#define size 30

void main(){
    int fd, n;
    char buffer[size];

    fd = open("sample.txt", O_RDWR);
    if ( fd == -1){
        printf("Error in opening file\n");
        exit(1);
    }

    printf("Reading first 10 characters >>\n");
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\n\nSkipping 5 characters from current position >>\n");
    lseek(fd, 5, SEEK_CUR);
    n = read(fd, buffer, 10);
    write(1, buffer, n);

    printf("\n\nGoing to 5th last character >> \n");
    lseek(fd, -5, SEEK_END);
    n = read(fd, buffer, 5);
    write(1, buffer, n);

    printf("\n\nGoing to 3rd character in file >> \n");
    lseek(fd, 3, SEEK_SET);
    n = read(fd, buffer, 10);
    write(1, buffer, n);
}

// read -> fd, buffer, size returns number of characters read
// write -> fd, buffer, size ( stdout fd -> 1)
// lseek -> fd, offset, SEEK_