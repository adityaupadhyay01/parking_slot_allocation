#include <stdio.h>
#include <string.h>

#define MAX_SLOTS 5
#define MAX_QUEUE 10

// parking slots (Array)
char slots[MAX_SLOTS][20];

// queue for waiting vehicles
char queue[MAX_QUEUE][20];
int front = 0, rear = -1;

void showSlots() {
    printf("\nParking Slots:\n");
    for(int i = 0; i < MAX_SLOTS; i++) {
        if(strlen(slots[i]) == 0)
            printf("Slot %d : FREE\n", i + 1);
        else
            printf("Slot %d : %s\n", i + 1, slots[i]);
    }
}

void parkVehicle(char vehicle[]) {

    for(int i = 0; i < MAX_SLOTS; i++) {
        if(strlen(slots[i]) == 0) {
            strcpy(slots[i], vehicle);
            printf("Vehicle %s parked at slot %d\n", vehicle, i + 1);
            return;
        }
    }

    // parking full → add to queue
    rear++;
    strcpy(queue[rear], vehicle);
    printf("Parking Full. %s added to waiting queue.\n", vehicle);
}

void exitVehicle(char vehicle[]) {

    for(int i = 0; i < MAX_SLOTS; i++) {

        if(strcmp(slots[i], vehicle) == 0) {

            printf("Vehicle %s exited from slot %d\n", vehicle, i + 1);
            strcpy(slots[i], "");

            if(front <= rear) {
                strcpy(slots[i], queue[front]);
                printf("Vehicle %s from queue parked at slot %d\n", queue[front], i + 1);
                front++;
            }

            return;
        }
    }

    printf("Vehicle not found.\n");
}

void showQueue() {
    printf("\nWaiting Queue:\n");
    for(int i = front; i <= rear; i++) {
        printf("%s\n", queue[i]);
    }
}

int main() {

    int choice;
    char vehicle[20];

    while(1) {

        printf("\n--- Parking System ---\n");
        printf("1. Park Vehicle\n");
        printf("2. Exit Vehicle\n");
        printf("3. Show Slots\n");
        printf("4. Show Queue\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter vehicle number: ");
                scanf("%s", vehicle);
                parkVehicle(vehicle);
                break;

            case 2:
                printf("Enter vehicle number: ");
                scanf("%s", vehicle);
                exitVehicle(vehicle);
                break;

            case 3:
                showSlots();
                break;

            case 4:
                showQueue();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}