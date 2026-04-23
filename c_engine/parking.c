#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum parking slots and queue size
#define MAX_SLOTS 5
#define MAX_QUEUE 10

// Array to store parked vehicles (slot system)
char slots[MAX_SLOTS][20];

// Array to store waiting vehicles (queue system)
char queue[MAX_QUEUE][20];

// Queue pointers
int front = 0, rear = -1;


// ======================= LOAD DATA =======================
// Loads existing parking and queue data from files
void loadData() {
    
    // Open slots file (read mode)
    FILE *fs = fopen("../data/slots.txt", "r");

    // Read all slot data
    for(int i = 0; i < MAX_SLOTS; i++) {
        fscanf(fs, "%s", slots[i]);
    }
    fclose(fs);

    // Open queue file (read mode)
    FILE *fq = fopen("../data/queue.txt", "r");

    // Reset queue pointers
    front = 0;
    rear = -1;

    char temp[20];

    // Read queue data until EOF
    while(fscanf(fq, "%s", temp) != EOF) {
        rear++;                         // Move rear forward
        strcpy(queue[rear], temp);     // Store vehicle in queue
    }
    fclose(fq);
}


// ======================= SAVE DATA =======================
// Saves updated parking and queue data to files
void saveData() {

    // Open slots file (write mode)
    FILE *fs = fopen("../data/slots.txt", "w");

    for(int i = 0; i < MAX_SLOTS; i++) {
        // If slot is empty string → store "EMPTY"
        fprintf(fs, "%s\n", strlen(slots[i]) ? slots[i] : "EMPTY");
    }
    fclose(fs);

    // Open queue file (write mode)
    FILE *fq = fopen("../data/queue.txt", "w");

    // Save only active queue elements
    for(int i = front; i <= rear; i++) {
        fprintf(fq, "%s\n", queue[i]);
    }
    fclose(fq);
}


// ======================= PARK VEHICLE =======================
// Tries to park vehicle in slot, else pushes to queue
void parkVehicle(char vehicle[]) {

    // Check for empty slot
    for(int i = 0; i < MAX_SLOTS; i++) {

        if(strcmp(slots[i], "EMPTY") == 0) {

            // Assign vehicle to slot
            strcpy(slots[i], vehicle);

            printf("Parked at slot %d", i+1);
            return;
        }
    }

    // If no slot available → add to queue
    rear++;
    strcpy(queue[rear], vehicle);

    printf("Added to queue");
}


// ======================= EXIT VEHICLE =======================
// Removes vehicle from slot and fills with queued vehicle (if any)
void exitVehicle(char vehicle[]) {

    // Search for vehicle in slots
    for(int i = 0; i < MAX_SLOTS; i++) {

        if(strcmp(slots[i], vehicle) == 0) {

            // Mark slot empty
            strcpy(slots[i], "EMPTY");

            // If queue has vehicles → assign next vehicle to slot
            if(front <= rear) {
                strcpy(slots[i], queue[front]);
                front++;   // Move queue forward
            }

            printf("Vehicle exited");
            return;
        }
    }

    // If vehicle not found
    printf("Vehicle not found");
}


// ======================= MAIN FUNCTION =======================
int main(int argc, char *argv[]) {

    // Check for valid arguments
    if(argc < 3) {
        printf("Invalid input");
        return 0;
    }

    // Load existing data from files
    loadData();

    // Command: park <vehicle>
    if(strcmp(argv[1], "park") == 0) {
        parkVehicle(argv[2]);
    }

    // Command: exit <vehicle>
    else if(strcmp(argv[1], "exit") == 0) {
        exitVehicle(argv[2]);
    }

    // Save updated data
    saveData();

    return 0;
}
