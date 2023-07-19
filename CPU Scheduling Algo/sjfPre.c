#include<stdio.h>
#include<stdlib.h>

struct pcb{
    int pid, at, bt, ct, tt, wt;
};

void main(){
    int n;
    printf("Enter the num. of processes>> ");
    scanf("%d", &n);
    
    struct pcb p[n];
    int btRemain[n];
    printf("PID AT BT\n");
    for(int i = 0; i<n; ++i){
        scanf("%d%d%d", &p[i].pid, &p[i].at, &p[i].bt);
        btRemain[i] = p[i].bt;
    }

    int min, index, completed = 0, curtime = 0, tottt = 0, totwt = 0, pid[40], ct[40], len = 0, j = 0, prev = -2;

    // Initializing completed array to 0
    int *isCompleted = (int *)calloc(sizeof(int), n);

    printf("\n\n");
    while (completed < n){
        int min = 99999, index = -1;

        for(int i = 0; i<n ; ++i){
            // Select process of minimum burst time remaining
            if ( p[i].at <= curtime && !isCompleted[i]){
                if ( btRemain[i] < min ){
                    index = i;
                    min = btRemain[i];
                }

                // Select process first arrived when burst time remained is same
                if ( btRemain[i] == btRemain[index]){
                    if ( p[i].at < p[index].at){
                        index = i;
                        min = btRemain[i];
                    }
                }
            }
        }

        if (index != -1){
            if ( prev == curtime - 1 && pid[j-1] == p[index].pid ){
                ++ct[j-1];
                prev = curtime;
            }
            else{
                pid[j] = p[index].pid;
                ct[j] = curtime + 1;
                ++len;
                ++j;
                prev = curtime;
            }
            --btRemain[index];
            ++curtime;

            if ( btRemain[index] == 0 ){
                // Process execution completed
                p[index].ct = curtime;
                p[index].tt = p[index].ct - p[index].at;
                p[index].wt = p[index].tt - p[index].bt;

                totwt += p[index].wt;
                tottt += p[index].tt;

                ++completed;
                isCompleted[index] = 1;
            }
        }
        else{
            if ( prev == curtime - 1 && pid[j-1] == -1){
                ++ct[j-1];
                prev = curtime;
            }
            else{
                pid[j] = -1;
                ct[j] = curtime + 1;
                ++len;
                ++j;
                prev = curtime;
            }
            ++curtime;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
    for(int i = 0; i<n; ++i)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);

    printf("\n\nGantt chart >> \n");
    for(int i = 0; i<len; ++i)
        printf("-------");
    printf("\n");
    for(int i = 0; i<len; ++i){
        if (pid[i] != -1)
            printf("  P%d  |", pid[i]);
        else
            printf(" IDLE |");
    }
    printf("\n");
    for(int i = 0; i<len; ++i)
        printf("-------");
    printf("\n0     ");
    for(int i = 0; i<len; ++i)
        printf("%d      ", ct[i]);
    printf("\n");

    printf("\n\nAvg turn around time >> %.2f\n", (float)tottt/n);
    printf("Avg waiting time >> %.2f\n", (float)totwt/n);
}