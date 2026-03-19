# 🚗 Parking Slot Allocation System (Console-Based Prototype in C)

## 📌 Overview

This project is a **console-based Parking Slot Allocation System** implemented in **C**.
It demonstrates how fundamental **Data Structures & Algorithms (DSA)** can be applied to solve a real-world problem — efficient parking management.

The system manages parking slots, allocates space to vehicles, and handles overflow using a waiting queue.

---

## 🎯 Objective

* Automate parking slot allocation
* Maintain real-time status of parking slots
* Enable vehicle entry and exit operations
* Handle overflow using a queue (FIFO)

---

## 🧠 Data Structures Used

### 1. Array

* Used to store parking slots
* Each index represents a slot
* Provides direct access to slot status

### 2. Queue

* Used for waiting vehicles when parking is full
* Follows **FIFO (First In First Out)** principle
* Ensures fair allocation

### 3. (Conceptual) Hashing

* Vehicle search is implemented using linear search
* Can be optimized using a hash table for **O(1)** lookup

---

## ⚙️ Features

* Park a vehicle
* Remove (exit) a vehicle
* Display parking slot status
* Display waiting queue
* Automatic allocation of freed slots to queued vehicles

---

## 🧩 System Workflow

### Vehicle Entry

1. Vehicle arrives
2. System checks for free slot
3. If available → assign slot
4. If full → add to waiting queue

### Vehicle Exit

1. Vehicle exits
2. Slot is freed
3. Next vehicle from queue gets assigned

---

## ⏱️ Time Complexity

| Operation        | Time Complexity |
| ---------------- | --------------- |
| Slot Allocation  | O(n)            |
| Vehicle Search   | O(n)            |
| Queue Operations | O(1)            |
| Exit Operation   | O(n)            |

---

## 🚀 Future Scope

* Implement **hash table** for faster vehicle lookup
* Add **GUI (Graphical Interface)**
* Integrate **IoT sensors** for real-time parking detection
* Develop a **mobile app for smart parking**
* Add **online reservation system**

---

## 🖥️ How to Run

### Step 1: Compile the program

```bash
gcc parking.c -o parking
```

### Step 2: Run the executable

```bash
./parking
```

---

## 💡 Sample Menu

```
1. Park Vehicle
2. Exit
```
