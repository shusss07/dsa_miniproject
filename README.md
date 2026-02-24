# 🦠 Epidemic Spread Simulator

A console-based C++ simulation of how an infectious disease spreads through a population modeled as a social contact network. Built as a mini project for the **Data Structures and Algorithms** course.

---

## 📌 DSA Concepts Used

| Concept | How It Is Used |
|---|---|
| **Graph (Adjacency List)** | Each person is a node. Each contact between two people is an edge |
| **BFS (Breadth-First Search)** | Disease spreads level by level — each level = one day |
| **Queue** | Manages the BFS frontier of currently infected people |
---

## 🎯 Features

- Random social network generation using a seeded random number generator
- Day-by-day epidemic spread visualization in the terminal
- Patient Zero selection to start the infection
- Quarantine mechanism — removes a person's edges from the graph, cutting off spread
- Grid display showing every person's state after each day
- Final statistics — total days, total infected, recovered, safe, and quarantined

---

## 🖥️ Sample Output

```
         EPIDEMIC SPREAD SIMULATOR
                    DAY 0
  H=Healthy  [I]=Infected  [R]=Recovered  [Q]=Quarantined

   0:[R]   1:[I]   2:[Q]   3: H    4: H    5: H    6: H    7: H    8:[I]   9: H
  10: H   11:[I]  12: H   13: H   14: H   15: H   16: H   17: H   18: H   19: H

  Day 0 Summary (Total: 30 people)
  [H] Healthy    : 22 people
  [I] Infected   :  6 people
  [R] Recovered  :  1 people
  [Q] Quarantine :  1 people

...

              SIMULATION COMPLETE

  Total Days Taken     : 4
  Total Ever Infected  : 30
  Never Infected (safe): 0
  Recovered            : 29
  Quarantined          : 1
```

---

## 🛠️ How to Compile and Run

### Requirements
- GCC / G++ compiler
- Any terminal (Command Prompt, PowerShell, Linux terminal)

### Compile
```bash
g++ epidemic_spread_simulation.cpp -o epidemic_spread_simulation
```

### Run
```bash
./epidemic_spread_simulation        # Linux / Mac
epidemic_spread_simulation.exe      # Windows
```

---

## 📁 Project Structure

```
epidemic-spread-simulator/
├── epidemic_spread_simulation.cpp   ← main source file
├── README.md                        ← this file
└── report/
    └── projectreport_SushantSharmaTimilsina_47.pdf          ← project report
```

---

## ⚙️ How It Works

1. A population of `n` people is created and everyone starts as **Healthy**
2. A random contact network is generated — each person gets 2 to 5 random contacts
3. One person is selected as **Patient Zero** and marked as Infected
4. Optionally, one or more people can be **Quarantined** before the simulation starts — their contact list is cleared so BFS cannot pass through them
5. BFS runs level by level — each level is one day
6. Every infected person spreads the disease to their Healthy contacts, then becomes Recovered
7. The simulation ends when no Infected people remain

---

## 🔬 Key Design Decisions

**Why Adjacency List over Adjacency Matrix?**
Social networks are sparse — most people only know a few others. An adjacency list uses O(V + E) space compared to O(V²) for a matrix, and iterating neighbors is faster since only existing connections are stored.

**Why does the State replace a visited[] array?**
In standard BFS, a boolean visited array prevents nodes from being enqueued twice. Here, the health state does the same job — once a person is Infected or Recovered, the `if (state == Healthy)` check fails permanently, so they can never be re-added to the queue.

**How are days tracked?**
The queue size is snapshot at the start of each iteration using `levelSize = Queue.size()`. Only that many people are processed in the current day. Anyone newly added to the queue during processing belongs to the next day's wave.

---

## 📊 Complexity

| Operation | Time Complexity | Space Complexity |
|---|---|---|
| BFS Spread | O(V + E) | O(V) |
| Add Edge | O(1) | — |
| Count State | O(V) | — |

---

## 🚀 Future Enhancements

- Add infection probability (not 100% guaranteed spread)
- Graphical visualization using SFML
- Interactive step mode — quarantine during simulation
- Re-infection model for endemic simulation
- DFS-based spread for comparison with BFS

---

## 👤 Author

**Sushant Sharma**
Roll No: 47
Department of Computer Science and Engineering
Kathmandu University

---

## 📄 License

This project was developed for academic purposes as part of the DSA course mini project.
