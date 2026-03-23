# 🚗 Parking Slot Allocation System

## 📌 Overview

This project is a **full-stack parking management system** that efficiently allocates parking slots using **Data Structures (Arrays & Queue)** implemented in **C**, integrated with a modern web interface.

It demonstrates how low-level logic (C) can be combined with web technologies using a **Node.js bridge server**.

---

## 🧠 Tech Stack

* **Frontend:** HTML, CSS, JavaScript
* **Backend Bridge:** Node.js (Express)
* **Core Logic:** C (DSA - Array & Queue)
* **Storage:** File System (`slots.txt`, `queue.txt`)

---

## ⚙️ Features

* 🚗 Park vehicle (auto slot allocation)
* 🚪 Exit vehicle (slot reallocation from queue)
* 📊 Queue management using FIFO
* 💾 Persistent storage using text files
* 🌐 Full-stack integration (Web + C backend)

---

## 🏗️ Architecture

```
Frontend (HTML/JS)
        ↓
Node.js Server (Express)
        ↓
C Engine (parking.c)
        ↓
File System (slots.txt / queue.txt)
```

---

## 📂 Project Structure

```
parking-slot-allocation/
│
├── backend/          # Node.js server
│   ├── server.js
│   ├── package.json
│
├── c_engine/         # C logic (DSA)
│   ├── parking.c
│
├── data/             # Storage
│   ├── slots.txt
│   ├── queue.txt
│
├── frontend/         # UI
│   ├── index.html
│   ├── script.js
│   ├── style.css
│
├── README.md
├── .gitignore
```

---

## 🚀 How to Run Locally

### 1️⃣ Compile C Program

```bash
cd c_engine
gcc parking.c -o parking
```

---

### 2️⃣ Start Backend Server

```bash
cd backend
npm install
node server.js
```

---

### 3️⃣ Run Frontend

Open:

```
frontend/index.html
```

---

## 🧪 Example Workflow

1. Enter vehicle number
2. Click **Park** → Allocates slot
3. Click **Exit** → Frees slot & assigns from queue

---

## ⚠️ Important Notes

* Do **not** upload compiled `.exe` file (compile locally)
* Ensure correct file paths for C execution
* Backend must be running before using frontend

---

## 💡 Key Learning Outcomes

* Integration of **low-level C logic with web applications**
* Understanding **process execution using Node.js (child_process)**
* Practical implementation of **Queue (FIFO)** and Arrays
* Real-world system design thinking

---

## 📸 (Optional)

*Add screenshots or demo GIF here*

---

## 📜 License

This project is for educational purposes.
