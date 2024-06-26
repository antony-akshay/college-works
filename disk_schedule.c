#include <stdio.h>
#include <stdlib.h>

void fcfs(int requests[], int num_requests, int head);
void scan(int requests[], int num_requests, int head);
void cscan(int requests[], int num_requests, int head);

int main() {
    int option;
    int requests[100];
    int num_requests, head_position;

    printf("ENTER THE NUMBER OF TRACKS : ");
    scanf("%d", &num_requests);
    printf("ENTER THE HEAD POINTER POSITION : ");
    scanf("%d", &head_position);
    printf("ENTER THE TRACKS TO BE TRAVERSED : ");
    for (int i = 0; i < num_requests; i++) {
        scanf("%d", &requests[i]);
    }

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. First Come First Serve (FCFS)\n");
        printf("2. SCAN Algorithm\n");
        printf("3. CSCAN Algorithm\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                fcfs(requests, num_requests, head_position);
                break;

            case 2:
                scan(requests, num_requests, head_position);
                break;

            case 3:
                cscan(requests, num_requests, head_position);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void fcfs(int requests[], int num_requests, int head) {
    int total_movements = 0;

    printf("TRAVERSED ORDER (FCFS): ");
    printf("%d => ", head);
    for (int i = 0; i < num_requests; i++) {
        printf("%d => ", requests[i]);
        total_movements += abs(requests[i] - head);
        head = requests[i];
    }
    printf("\b\b\b.  \n");
    printf("TOTAL HEAD MOVEMENTS (FCFS): %d\n", total_movements);
}

void scan(int requests[], int num_requests, int head) {
    int total_movements = 0;
    int sorted_requests[100];

    // Copy requests array to sorted_requests array for sorting
    for (int i = 0; i < num_requests; i++) {
        sorted_requests[i] = requests[i];
    }

    // Sorting the requests array
    for (int i = 0; i < num_requests; i++) {
        for (int j = 0; j < num_requests - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    int direction;
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    printf("TRAVERSED ORDER (SCAN): ");
    if (direction == 0) {
        // Move towards left
        printf("%d => ", head);
        for (int i = 0; i < num_requests; i++) {
            if (sorted_requests[i] < head) {
                printf("%d => ", sorted_requests[i]);
                total_movements += abs(sorted_requests[i] - head);
                head = sorted_requests[i];
            }
        }
        printf("0 => ");
        total_movements += head;
        head = 0;
        for (int i = num_requests - 1; i >= 0; i--) {
            if (sorted_requests[i] > head) {
                printf("%d => ", sorted_requests[i]);
                total_movements += abs(sorted_requests[i] - head);
                head = sorted_requests[i];
            }
        }
    } else {
        // Move towards right
        printf("%d => ", head);
        for (int i = num_requests - 1; i >= 0; i--) {
            if (sorted_requests[i] > head) {
                printf("%d => ", sorted_requests[i]);
                total_movements += abs(sorted_requests[i] - head);
                head = sorted_requests[i];
            }
        }
        printf("199 => ");
        total_movements += (199 - head);
        head = 199;
        for (int i = 0; i < num_requests; i++) {
            if (sorted_requests[i] < head) {
                printf("%d => ", sorted_requests[i]);
                total_movements += abs(sorted_requests[i] - head);
                head = sorted_requests[i];
            }
        }
    }
    printf("\b\b\b.  \n");
    printf("TOTAL HEAD MOVEMENTS (SCAN): %d\n", total_movements);
}

void cscan(int requests[], int num_requests, int head) {
    int total_movements = 0;
    int sorted_requests[100];

    // Copy requests array to sorted_requests array for sorting
    for (int i = 0; i < num_requests; i++) {
        sorted_requests[i] = requests[i];
    }

    // Sorting the requests array
    for (int i = 0; i < num_requests; i++) {
        for (int j = 0; j < num_requests - i - 1; j++) {
            if (sorted_requests[j] > sorted_requests[j + 1]) {
                int temp = sorted_requests[j];
                sorted_requests[j] = sorted_requests[j + 1];
                sorted_requests[j + 1] = temp;
            }
        }
    }

    printf("TRAVERSED ORDER (C-SCAN): ");
    printf("%d => ", head);
    for (int i = 0; i < num_requests; i++) {
        if (sorted_requests[i] >= head) {
            printf("%d => ", sorted_requests[i]);
            total_movements += abs(sorted_requests[i] - head);
            head = sorted_requests[i];
        }
    }
    printf("199 => 0 => ");
    total_movements += (199 - head) + 199;
    head = 0;
    for (int i = 0; i < num_requests; i++) {
        if (sorted_requests[i] < head) {
            printf("%d => ", sorted_requests[i]);
            total_movements += abs(sorted_requests[i] - head);
            head = sorted_requests[i];
        }
    }
    printf("\b\b\b.  \n");
    printf("TOTAL HEAD MOVEMENTS (C-SCAN): %d\n", total_movements);
}
