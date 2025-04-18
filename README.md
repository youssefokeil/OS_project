# 🖥️ CPU Scheduler Simulator

A GUI-based desktop application that simulates various CPU scheduling algorithms in real-time. Supports FCFS, SJF, Priority, and Round Robin scheduling with live updates and visualization.

---

## 🚀 Features

- Live simulation with 1 time unit = 1 second
- Dynamic process addition during scheduling
- Gantt Chart displayed live
- Real-time Remaining Burst Time table
- Average Waiting Time and Turnaround Time calculation
- Option to run in **Static Mode** (run current processes only)
- Executable-ready build for easy distribution

---

## 🧠 Supported Scheduling Algorithms

1. **FCFS** (First Come First Serve)
2. **SJF**
   - Preemptive
   - Non-Preemptive
3. **Priority**
   - Preemptive
   - Non-Preemptive
   - Lower number = higher priority
4. **Round Robin**
   - Requires Time Quantum

> 💡 The program only requests relevant input based on the selected algorithm (e.g., FCFS doesn't ask for priority).

---

## 📸 GUI Preview

> _Insert screenshots or screen recordings here if available._

---

## 🧾 Input Requirements

On startup, you will be prompted for:

1. Scheduler Type
2. Number of initial processes
3. Process information:
   - **PID** (Process ID)
   - **Arrival Time**
   - **Burst Time**
   - **Priority** (if using Priority scheduling)
   - **Time Quantum** (if using Round Robin)

Processes can be added dynamically at runtime via the GUI.

---

## 📈 Output

- **Gantt Chart** showing execution order
- **Live Burst Time Table** with real-time updates
- **Average Waiting Time**
- **Average Turnaround Time**

---

## 🛠️ Technologies Used

- Language: C++
- GUI Framework: Qt
- Threading / Timers for real-time simulation

---

## 📦 How to Run

1. Clone the repo:
   ```bash
   git clone https://github.com/your-username/your-repo-name.git
   cd your-repo-name
