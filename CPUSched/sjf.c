#include <stdio.h>

int main() {
    int P[10], bt[10], at[10], tat[10], ct[10], wt[10], n;
    float tot_tat = 0, tot_wt = 0;

    printf("Enter the number of Processes: ");
    scanf("%d", &n);

    printf("Enter the arrival time and burst time of each process\n\n");
    for (int i = 0; i < n; i++) {
        printf("Arrival time of process[%d]:", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time of process[%d]:", i + 1);
        scanf("%d", &bt[i]);
        P[i] = i + 1;
        printf("\n");
    }

    // Sorting based on Arrival Time and Burst Time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[i] || (bt[j] == bt[i] && at[j] < at[i])) {
                // Swap burst times
                int tempy = bt[i];
                bt[i] = bt[j];
                bt[j] = tempy;

                // Swap arrival times
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // Swap process IDs
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }

    int sum = at[0];
    for (int j = 0; j < n; j++) {
        if (sum < at[j]) {
            sum = at[j];
        }
        sum = sum + bt[j];
        ct[j] = sum;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        tot_tat = tot_tat + tat[i];
    }

    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];
        tot_wt = tot_wt + wt[i];
    }

    printf("ProcessID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P[%d]\t\t%d\t%d\t%d\t%d\t%d\n", P[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time =%f\n", tot_tat / n);
    printf("Average waiting Time =%.2f\n", tot_wt / n);

    return 0;
}