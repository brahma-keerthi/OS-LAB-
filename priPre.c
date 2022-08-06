#include<stdio.h>
#include<stdlib.h>

struct pcb{
    int pid, at, bt, pr, ct, tt, wt;
};

void main(){
    int n;
    printf("Enter num. of processes >> ");
    scanf("%d", &n);

    struct pcb p[n];
    int btRemain[n];
    printf("PID  AT  BT  PRI\n");
    for(int i = 0; i<n; ++i){
        scanf("%d%d%d%d", &p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
        btRemain[i] = p[i].bt;
    }

    // Initializing completed array to 0
    int *isCompleted = (int *)calloc(sizeof(int), n);

    int completed = 0, curtime = 0, totwt = 0 , tottt = 0, max, index, prev = -2, pid[20], ct[20], j = 0, len = 0;

    printf("\n");
    while ( completed < n ){
        max = -1, index = -1;

        for(int i = 0; i<n; ++i){
            // Selecting process of highest priority in current time
            if ( p[i].at <= curtime && !isCompleted[i]){
                if ( p[i].pr > max ){
                    max = p[i].pr;
                    index = i;
                }

                // for same priority select process of lowest at
                if ( p[i].pr == p[index].pr ){
                    if ( p[i].at < p[index].at ){
                        index = i;
                        max = p[i].pr;
                    }
                }
            }
        }

        if ( index != -1 ){
            if ( prev == curtime -1 && pid[j-1] == p[index].pid){
                ++ct[j-1];
                prev = curtime;
            }
            else{
                ct[j] = curtime + 1;
                pid[j] = p[index].pid;
                ++len;
                ++j;
                prev = curtime;
            }
            --btRemain[index];
            ++curtime;

            if ( btRemain[index] == 0 ){
                // If process finished execution
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
            if ( prev == curtime -1 && pid[j-1] == -1){
                ++ct[j-1];
                prev = curtime;
            }
            else{
                ct[j] = curtime + 1;
                pid[j] = -1;
                ++len;
                ++j;
                prev = curtime;
            }
            ++curtime;
        }
    }

    printf("PID\tAT\tBT\tPRI\tCT\tTT\tWT\n");
    for(int i = 0; i<n; ++i)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tt, p[i].wt);

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