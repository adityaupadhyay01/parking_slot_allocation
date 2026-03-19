#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SLOTS 5
#define MAX_QUEUE 10

char slots[MAX_SLOTS][20];
char queue[MAX_QUEUE][20];
int front = 0, rear = -1;

// LOAD DATA
void loadData() {
    FILE *fs = fopen("../data/slots.txt", "r");
    for(int i = 0; i < MAX_SLOTS; i++) {
        fscanf(fs, "%s", slots[i]);
    }
    fclose(fs);

    FILE *fq = fopen("../data/queue.txt", "r");
    front = 0;
    rear = -1;
    char temp[20];
    while(fscanf(fq, "%s", temp) != EOF) {
        rear++;
        strcpy(queue[rear], temp);
    }
    fclose(fq);
}

// SAVE DATA
void saveData() {
    FILE *fs = fopen("../data/slots.txt", "w");
    for(int i = 0; i < MAX_SLOTS; i++) {
        fprintf(fs, "%s\n", strlen(slots[i]) ? slots[i] : "EMPTY");
    }
    fclose(fs);

    FILE *fq = fopen("../data/queue.txt", "w");
    for(int i = front; i <= rear; i++) {
        fprintf(fq, "%s\n", queue[i]);
    }
    fclose(fq);
}

// PARK
void parkVehicle(char vehicle[]) {
    for(int i = 0; i < MAX_SLOTS; i++) {
        if(strcmp(slots[i], "EMPTY") == 0) {
            strcpy(slots[i], vehicle);
            printf("Parked at slot %d", i+1);
            return;
        }
    }

    rear++;
    strcpy(queue[rear], vehicle);
    printf("Added to queue");
}

// EXIT
void exitVehicle(char vehicle[]) {
    for(int i = 0; i < MAX_SLOTS; i++) {
        if(strcmp(slots[i], vehicle) == 0) {
            strcpy(slots[i], "EMPTY");

            if(front <= rear) {
                strcpy(slots[i], queue[front]);
                front++;
            }

            printf("Vehicle exited");
            return;
        }
    }
    printf("Vehicle not found");
}

int main(int argc, char *argv[]) {

    if(argc < 3) {
        printf("Invalid input");
        return 0;
    }

    loadData();

    if(strcmp(argv[1], "park") == 0) {
        parkVehicle(argv[2]);
    }
    else if(strcmp(argv[1], "exit") == 0) {
        exitVehicle(argv[2]);
    }

    saveData();
    return 0;
}