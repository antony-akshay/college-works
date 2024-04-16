#include<stdio.h>


void sortProcesses(int n, int at[], int bt[]) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }
}

int main() {
    int i, n, at[20], bt[20], tat[20], wt[20], atat = 0, awt = 0, temp[30];
    printf("Enter the no of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter the burst time and arrival time of process %d: ", i);
        scanf("%d %d", &bt[i], &at[i]);
    }
    
    sortProcesses(n, at, bt);
    
    temp[0] = 0;
    printf("process\twt\ttat\n"); 
    for (i = 0; i < n; i++) {
        temp[i+1] = temp[i] + bt[i];
        wt[i] = temp[i] - at[i];
        if (wt[i] < 0) {
            wt[i] = 0; 
        }
        tat[i] = wt[i] + bt[i];
        awt += wt[i];
        atat += tat[i];
        printf("%d\t%d\t%d\n", i, wt[i], tat[i]);
    }
    awt /= n; 
    atat /= n; 
    printf("avg wt: %d\n", awt);
    printf("avg tat: %d\n", atat);
    return 0;
}

