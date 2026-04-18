<div align="center">

# Parking Slot Allocation System

**A full-stack parking management system powered by C (DSA) + Node.js + Web**

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Node.js](https://img.shields.io/badge/Node.js-339933?style=for-the-badge&logo=nodedotjs&logoColor=white)
![Express](https://img.shields.io/badge/Express-000000?style=for-the-badge&logo=express&logoColor=white)
![HTML5](https://img.shields.io/badge/HTML5-E34F26?style=for-the-badge&logo=html5&logoColor=white)
![JavaScript](https://img.shields.io/badge/JavaScript-F7DF1E?style=for-the-badge&logo=javascript&logoColor=black)

</div>

---

## Overview

A **full-stack parking management system** that efficiently allocates parking slots using **Data Structures (Arrays & Queue)** implemented in **C**, bridged to a modern web interface via **Node.js**.

This project demonstrates how **low-level systems programming in C** can power a real-world web application — combining DSA fundamentals with full-stack development.

---

## Tech Stack

| Layer | Technology |
|---|---|
| Frontend | HTML, CSS, JavaScript |
| Backend Bridge | Node.js (Express) |
| Core Logic | C (Arrays & Queue DSA) |
| Storage | File System (`slots.txt`, `queue.txt`) |

---

## Features

- **Park Vehicle** — Auto-allocates the next available slot
- **Exit Vehicle** — Frees the slot and reassigns it from the queue
- **Queue Management** — FIFO-based waiting list when the lot is full
- **Persistent Storage** — State saved across sessions via text files
- **Full-Stack Integration** — Web UI communicates with C engine through Node.js

---

## Architecture
```
Frontend (HTML/JS)
        │
        ▼
Node.js Server (Express)        ← HTTP API layer
        │
        ▼  child_process.exec()
C Engine (parking.c)            ← Core DSA logic
        │
        ▼
File System (slots.txt / queue.txt)
```

The Node.js server acts as a **bridge**: it receives HTTP requests from the browser, invokes the compiled C binary using `child_process`, and returns the result to the frontend.

---

## Project Structure
```
parking-slot-allocation/
│
├── backend/
│   ├── server.js          # Express server & C process bridge
│   └── package.json
│
├── c_engine/
│   └── parking.c          # Core DSA logic (Arrays + Queue)
│
├── data/
│   ├── slots.txt          # Slot state (occupied/free)
│   └── queue.txt          # Waiting queue (FIFO)
│
├── frontend/
│   ├── index.html         # Main UI
│   ├── script.js          # API calls & DOM updates
│   └── style.css          # Styling
│
├── .gitignore
└── README.md
```

---

## Getting Started

### Prerequisites

- GCC compiler
- Node.js (v14+)
- npm

---

### Step 1 — Compile the C Engine
```bash
cd c_engine
gcc parking.c -o parking
```

> Do **not** commit the compiled binary. Add it to `.gitignore`.

---

### Step 2 — Start the Backend Server
```bash
cd backend
npm install
node server.js
```

The server will start on `http://localhost:3000` (or your configured port).

---

### Step 3 — Open the Frontend

Open `frontend/index.html` directly in your browser, or serve it via a quick static server:
```bash
npx serve frontend
```

---

## 🔌 API Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| `POST` | `/park` | Parks a vehicle, returns allocated slot number |
| `POST` | `/exit` | Removes a vehicle, triggers queue reassignment |
| `GET` | `/status` | Returns current slot and queue state |

---

## Example Workflow
```
1. Enter vehicle number  →  e.g., MH12AB1234
2. Click [Park]          →  Slot S3 allocated
3. Lot is full           →  Next vehicle added to waiting queue
4. Click [Exit] on S3    →  S3 freed, queued vehicle auto-assigned
```

---

## Troubleshooting

| Issue | Fix |
|---|---|
| `gcc: command not found` | Install GCC: `sudo apt install gcc` (Linux) or MinGW (Windows) |
| `Cannot connect to server` | Ensure `node server.js` is running before opening the frontend |
| `parking: No such file` | Recompile the C engine and verify the binary path in `server.js` |
| Stale slot / queue state | Delete `data/slots.txt` and `data/queue.txt` to reset all data |

---

## Key Learning Outcomes

- Integrating **low-level C logic** with modern web applications
- Using **Node.js `child_process`** to execute native binaries from a server
- Practical implementation of **Queue (FIFO)** and **Array** data structures
- **Persistent file-based storage** without a database
- Real-world **multi-layer system design** thinking

---

## Contributing

Contributions are welcome!

1. Fork the repository
2. Create a feature branch: `git checkout -b feature/your-feature`
3. Commit your changes: `git commit -m "Add your feature"`
4. Push to the branch: `git push origin feature/your-feature`
5. Open a Pull Request

---

## Author
LinkdIn:-

---

## License

This project is for **educational purposes**.
---
