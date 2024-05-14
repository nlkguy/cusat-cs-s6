#include <stdio.h>
#include <stdlib.h>

struct FCFS{
        int num;
        int ArrivalTime;
        int BurstTime;
        int CompletionTime;
        int TurnAroundTime;
        int WaitingTime;
    };
    
void main(){

    struct FCFS process[20];
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter %d processes: \n\n",n);
    
    for(int i=0;i<n;i++){
        process[i].num=i+1;
        printf("Enter %d process's Arrival Time: ", i+1);
        scanf("%d",&process[i].ArrivalTime);
        printf("Enter %d process's Burst Time: ", i+1);
        scanf("%d",&process[i].BurstTime);
        printf("-----------------------------------------\n");
    }

    struct FCFS temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(process[i].ArrivalTime>process[j].ArrivalTime){
                temp = process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }

    float total_tt=0;
    float total_wt=0;
    int timer=process[0].ArrivalTime;

    for(int i=0;i<n;i++){
        if(timer<process[i].ArrivalTime){
            timer=process[i].ArrivalTime+process[i].BurstTime;
        }else{
            timer+=process[i].BurstTime;
        }

        process[i].CompletionTime=timer;
        process[i].TurnAroundTime=process[i].CompletionTime-process[i].ArrivalTime;
        process[i].WaitingTime=process[i].TurnAroundTime-process[i].BurstTime;
    }

    for(int i=0;i<n;i++){
        total_tt+=process[i].TurnAroundTime;
        total_wt+=process[i].WaitingTime;
    }

    float avg_tt=total_tt/n;
    float avg_wt=total_wt/n;

    printf("\n\nProcess No.\tArrival Time\tBurst Time\tComplition Time\tTurnAround Time\tWaiting Time");
    for(int i=0;i<n;i++){
        printf("\np%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",process[i].num, process[i].ArrivalTime, process[i].BurstTime, process[i].CompletionTime, process[i].TurnAroundTime, process[i].WaitingTime);
    }

    printf("\n\nAverage TurnAround Time is :%f", avg_tt);
    printf("\nAverage Waiting time is: %f", avg_wt);
}
