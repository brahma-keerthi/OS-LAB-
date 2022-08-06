#include<stdio.h>
#include<stdlib.h>

struct pcb{
    int pid, at, bt, ct, tt, wt;
};

void main(){
    int n;
    printf("Enter num of processes >> ");
    scanf("%d", &n);

    struct pcb p[n];

    printf("PID  AT  BT\n");
    for(int i= 0; i<n; ++i)
        scanf("%d%d%d", &p[i].pid, &p[i].at, &p[i].bt);

    // Initializing completed array to 0
    int * isCompleted = (int *)calloc(sizeof(int),n);

    int min, index , completed = 0, curtime = 0, pid[20], ct[20], len = n, prev = -2, tottt = 0, totwt = 0, j = 0;

    while ( completed != n ){
        index = -1, min = 99999;

        // Selection of process of minimum at
        for(int i = 0; i<n; ++i){
            if (p[i].at <= curtime && !isCompleted[i]){
                if ( min > p[i].at){
                    index = i;
                    min = p[i].at;
                }
            }
        }

        if ( index != -1 ){
            p[index].ct = p[index].bt + curtime;
            p[index].tt = p[index].ct - p[index].at;
            p[index].wt = p[index].tt - p[index].bt;

            tottt += p[index].tt;
            totwt += p[index].wt;

            ct[j] = p[index].ct;
            pid[j] = p[index].pid;
            ++j;

            curtime = p[index].ct;
            ++completed;
            isCompleted[index] = 1;
        }
        else{
            if (prev == curtime - 1){
                ct[j-1] = curtime + 1;
                prev = curtime + 1;
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

    printf("PID\tAT\tBT\tCT\tTT\tWT\n");
    for(int i = 0; i<n; ++i)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);

    printf("\nGantt Chart >> \n");
    for(int i = 0; i<len; ++i)
        printf("-------");
    printf("\n");
    for(int i = 0; i<len; ++i){
        if ( pid[i] != -1 )
            printf("  P%d  |", pid[i]);
        else
            printf(" IDLE |");
    }
    printf("\n");
    for(int i = 0; i<len; ++i)
        printf("-------");
    printf("\n");
    printf("0     ");
    for(int i = 0; i<len; ++i)
        printf("%d      ", ct[i]);

    printf("\n\nAvg turn around time >> %.2f\n", (float)tottt/n);
    printf("Avg waiting time >> %.2f\n", (float)totwt/n);
}