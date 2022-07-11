#include<stdio.h>
 
int main(){
    int bt[20], procs[20], wt[20], tat[20], prio[20], i, j, n, total = 0, pos, temp;
    float avg_wt, avg_tat;
    printf("Enter number of Process:");
    scanf("%d", &n);
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++){
     printf("Burst Time:");
     scanf("%d",&bt[i]);
     printf("Priority:");
     scanf("%d",&prio[i]);
     procs[i]=i+1;          
    }
    for(i=0;i<n;i++){
    pos=i;
     for(j=i+1;j<n;j++){
        if(prio[j]<prio[pos])
         pos=j;}
 
     temp=prio[i];
     prio[i]=prio[pos];
     prio[pos]=temp;
 
     temp=bt[i];
     bt[i]=bt[pos];
     bt[pos]=temp;
 
     temp=procs[i];
     procs[i]=procs[pos];
     procs[pos]=temp;}
 
    wt[0]=0; 
 
   
    for(i=1;i<n;i++){
        wt[i]=0;
     for(j=0;j<i;j++)
        wt[i]+=bt[j];
     total += wt[i];}
 
    avg_wt = (float)total/n;
    total = 0;
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++){
     tat[i]=bt[i]+wt[i];
     total+=tat[i];
     printf("\n%d\t\t%d\t\t%d\t\t%d", procs[i], bt[i], wt[i], tat[i]);}
    avg_tat=(float)total/n;
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
    }
