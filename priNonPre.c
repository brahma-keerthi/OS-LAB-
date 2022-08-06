#include<stdio.h>
#include<stdlib.h>

struct pcb{
    int pid, at, bt, ct, wt, tt, pr;
};

void main(){
    int n;
    printf("Enter num. of processes>> ");
    scanf("%d", &n);
    struct pcb p[n];
    
    // Initializing completed array to 0
    int * isCompleted = (int *)calloc(sizeof(int), n);

    printf("PCB AT BT PRI\n");
    for(int i = 0 ; i<n; ++i)
        scanf("%d%d%d%d", &p[i].pid, &p[i].at, &p[i].bt, &p[i].pr);
    printf("\n\n");

    int completed = 0, curtime = 0, totwt = 0, tottt = 0, temp;
    int pid[n], ct[n], j= 0;

    while (completed < n){
        int index = -1, m = -1;
        for(int i =0; i<n ; ++i){
            if ( p[i].at <= curtime && !isCompleted[i]){
                // Select process of max priority
                if ( m < p[i].pr ){
                    index = i;
                    m = p[i].pr;
                }

                // If priority is same sort based on at
                if ( p[i].pr == p[index].pr ){
                    if (p[i].at < p[index].at){
                        index = i;
                        m = p[i].pr;
                    }
                }
            }
        }

        if (index != -1){
            p[index].ct = curtime + p[index].bt;
            p[index].tt = p[index].ct - p[index].at;
            p[index].wt = p[index].tt - p[index].bt;

            pid[j] = p[index].pid;
            ct[j] = p[index].ct;
            ++j;

            totwt += p[index].wt;
            tottt += p[index].tt;

            ++completed;
            if (completed == 1) temp = curtime;
            curtime = p[index].ct;
            isCompleted[index] = 1;
        }
        else{
            printf("CPU idle at %d - %d time\n" , curtime, curtime + 1);
            ++curtime;
        }
    }

    printf("PID\tAT\tBT\tPRI\tCT\tTT\tWT\n");
    for(int i = 0; i<n; ++i)
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].pr, p[i].ct, p[i].tt, p[i].wt );

    printf("\n\nGantt Chart >> \n");
    for(int i = 0; i<n; ++i)
        printf("-------");
    printf("\n");
    for(int i= 0; i<n; ++i)
        printf("  P%d  |", pid[i]);
    printf("\n");
    for(int i = 0; i<n; ++i)
        printf("-------");
    printf("\n");
    printf("%d     ", temp);
    for(int i = 0; i<n; ++i)
        printf("%d      ", ct[i]);
    printf("\n\n");

    printf("\nAvg turn around time >> %.2f\n", (float)tottt/n);
    printf("Avg waiting time >> %.2f\n", (float)totwt/n);
}