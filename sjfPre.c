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

    int min, index, completed = 0, curtime = 0, tottt = 0, totwt = 0;

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
            printf("CPU idle at %d - %d\n", curtime, curtime + 1);
            ++curtime;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTT\tWT\n");
    for(int i = 0; i<n; ++i)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);

    printf("\nAvg turn around time >> %.2f\n", (float)tottt/n);
    printf("Avg waiting time >> %.2f\n", (float)totwt/n);
}