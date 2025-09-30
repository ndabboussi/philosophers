# 🍽️ Philosophers

## 🧠 Project Overview

*Philosophers* is a classic concurrency exercise from **42 School**.  
The goal is to simulate the famous *Dining Philosophers Problem* (Edsger Dijkstra, 1965) while respecting strict rules about **threads**, **synchronization**, and **timing**.

### 📌 The Story

Imagine several philosophers sitting around a round table. Between each of them lies a fork. A philosopher’s life consists of alternating between **thinking**, **eating**, and **sleeping**.  

To eat, a philosopher must pick up **two forks** (the one on their left and the one on their right). Once finished, they put the forks back and start thinking again.  

The challenge:  
- Ensure philosophers never starve.  
- Prevent *deadlocks* (e.g., everyone grabbing their left fork at the same time and blocking forever).  
- Monitor their lives with precise timing (a philosopher "dies" if they don’t eat within a given time).  

---

## 🚀 How to Run

### ✅ Requirements
- A Unix-like environment (Linux, macOS, or WSL on Windows)  
- `gcc` or `clang` compiler  
- `make`  

### ⚙️ Installation
Clone the repository and compile:
git clone https://github.com/ndabboussi/philosophers.git
cd philosophers
make

### ▶️ Usage
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_must_eat]

Example: 
./philo 5 800 200 200
➡️ 5 philosophers, each has 800ms before starving, 200ms to eat, 200ms to sleep.

./philo 5 800 200 200 7
➡️ Same as above, but the simulation ends once each philosopher has eaten 7 times.

### 🛠 Debugging with Valgrind
Check thread safety with Helgrind:
valgrind --tool=helgrind ./philo 5 800 200 200
⚠️ This slows execution and may affect timing.

---

## 🔑 Key Challenges
| Challenge                  | Why it matters                                                             |
| -------------------------- | -------------------------------------------------------------------------- |
| **Thread synchronization** | Philosophers (threads) must safely access shared resources (forks, state). |
| **Avoiding deadlocks**     | Without careful design, philosophers may block each other forever.         |
| **Accurate timing**        | Keep precise track of last meal to detect starvation.                      |
| **Monitoring system**      | A supervisor checks deaths or completion of required meals.                |
| **Edge cases**             | Single philosopher, zero philosophers, optional meals parameter, etc.      |
| **Clean printing**         | Prevent overlapping logs with synchronized output.                         |

---

## 📚 Resources I Used

- [🎥 Threads in C explained](https://www.youtube.com/watch?v=d9s_d28yJq0)  
- [🎥 Mutex explained](https://www.youtube.com/watch?v=oq29KUy29iQ)
