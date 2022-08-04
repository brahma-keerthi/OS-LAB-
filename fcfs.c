#include<stdio.h>
#include<stdlib.h>

struct pcb{
    int pid, at, bt, ct, wt, tt;
    struct pcb * link;
};
int totWT = 0, totTT = 0;

typedef struct pcb * PCB;

PCB create(){
    PCB new = (PCB)malloc(sizeof(struct pcb));
    if ( new == NULL){
        printf("Memory error!!\n");
        return NULL;
    }
    new -> link = NULL;
    return new;
}

// ReadyQ is ordering the linked list
PCB readyQ(PCB ready, PCB new){
    if ( ready == NULL || new -> at <= ready -> at ){
        new -> link = ready;
        return new;
    }
        
    PCB temp = ready -> link;
    PCB prev = ready;
    while ( temp != NULL && temp -> at < new -> at ){
        prev = temp;
        temp = temp -> link;
    }

    prev -> link = new;
    new -> link = temp;
    return ready;
}

void calculate(PCB ready){
    int ct = ready -> at;
    PCB temp = ready;

    while ( temp != NULL){
        if ( ct < temp -> at)
            ct = temp -> at;

        ct += temp -> bt;
        temp -> ct = ct;
        temp -> tt = temp-> ct - temp -> at;
        temp -> wt = temp -> tt - temp -> bt;
        totTT += temp -> tt;
        totWT += temp -> wt;
        temp = temp -> link;
    }
}

void main(){
    int n;
    PCB ready = NULL;
    PCB new;
    printf("Enter the number of processes >> ");
    scanf("%d", &n);

    printf("Enter PID  AT  BT\n");
    for(int i = 0; i<n; ++i){
        new = create();
        int pid, at, bt;
        scanf("%d%d%d", &new -> pid, &new -> at, &new -> bt);
        ready = readyQ(ready, new);
    }

    calculate(ready);

    printf("PID\tAT\tBT\tCT\tTT\tWT\n");
    PCB temp = ready;
    while(temp != NULL){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", temp -> pid, temp -> at, temp -> bt, temp -> ct, temp -> tt, temp -> wt);
        temp = temp -> link;
    }
}