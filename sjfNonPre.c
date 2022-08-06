#include<stdio.h>
#include<stdlib.h>

struct pcb {
    int pid, at, bt, wt, tt, ct;
};

void main(){
    int n;
    printf("Enter the number of processes >> ");
    scanf("%d",&n);
    struct pcb p[n];

    printf("PID  AT  BT\n");
    for(int i = 0 ; i<n ; ++i)
        scanf("%d%d%d", &p[i].pid, &p[i].at, &p[i].bt);

    // Initializing is completed array to 0
    int * isCompleted = (int *)calloc(sizeof(int), n);

    int curtime = 0, completed = 0, totwt = 0, tottt = 0, temp;
    int pid[n], ct[n], j = 0;

    while ( completed < n ){
        // Finding process from ready queue
        int min = 999999, index = -1;
        // Seleting process that is arrived and is not completed
        for(int i = 0; i<n; ++i){
            if ( p[i].at <= curtime && !isCompleted[i]){
                if (p[i].bt < min){
                    min = p[i].bt;
                    index = i;
                }

            // If two process has same bt, select process that has arrived first
                if (p[i].bt == min){
                    if (p[i].at < p[index].at){
                        index = i;
                        min = p[i].bt;
                    }
                }
            }
        }

        if ( index != -1 ){
            p[index].ct = curtime + p[index].bt;
            p[index].tt = p[index].ct - p[index].at;
            p[index].wt = p[index].tt - p[index].bt;
            tottt += p[index].tt;
            totwt += p[index].wt;

            pid[j] = p[index].pid;
            ct[j] = p[index].ct;
            ++j;

            isCompleted[index] = 1;
            ++completed;
            if (completed == 1) temp = curtime;
            curtime = p[index].ct;
        }
        else{
            // CPU idle
            printf("CPU idle at %d - %d time\n", curtime, ++curtime);
        }
    }

    printf("\n\nPID\tAT\tBT\tCT\tTT\tWT\n");
    for(int i = 0; i<n ; ++i)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);

    printf("\nGantt chart\n");
	for(int i = 0;i<n; ++i)
		printf("-----");
	printf("\n");
	for(int i = 0;i<n; ++i)
		printf(" P%d |", pid[i]);
	printf("\n");
	for(int i = 0;i<n; ++i)
		printf("-----");
	printf("\n");
	printf("%d   ", temp);
	for(int i = 0;i<n; ++i)
		printf("%d    ", ct[i]);
	printf("\n");


    printf("\n\nAvg turn around time >> %.2f\n", (float)tottt/n);
    printf("Avg waiting time >> %.2f\n", (float)totwt/n);
}