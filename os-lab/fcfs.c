#include <stdio.h>

#define MAX 100

int pid[MAX], at[MAX], bt[MAX], wt[MAX], tat[MAX], ct[MAX];

void calculateTimes(int n) {
    int completion_time = 0;
    for (int i = 0; i < n; i++) {
        wt[i] = completion_time;
        tat[i] = completion_time + bt[i] - at[i];
        completion_time = tat[i] + at[i];
        ct[i] = completion_time;
    }
}

void displayTimes(int n) {
    printf("PID | Arrival | Burst | Wait | Turnaround | Completion\n");
    for (int i = 0; i < n; i++) {
        printf("%3d | %7d | %5d | %4d | %10d | %10d\n",
               pid[i], at[i], bt[i], wt[i], tat[i], ct[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter PID for P%d: ", i + 1);
        scanf("%d", &pid[i]);
        printf("Enter arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    calculateTimes(n);
    displayTimes(n);

    return 0;
}

