# 🎮 Conway's Game of Life - Complete Guide

Welcome to the simulation! This project is a C++ implementation of Conway's Game of Life using the Raylib library. Below you will find everything you need to know to control the simulation and understand the laws of this digital universe.

---

## 🕹️ Controls

You can interact with the grid and control the flow of life using the following keys and mouse actions:

### 🖱️ Mouse Controls
* **Left Mouse Button (Hold/Click):** Toggle cell state. It allows you to draw patterns on the grid manually by activating cells under the cursor.

### ⌨️ Keyboard Commands

| Key | Action | Description |
| :--- | :--- | :--- |
| **ENTER** | **Start** | Starts the simulation. Life begins to evolve based on the rules. |
| **SPACE** | **Stop** | Pauses the simulation. Useful for observing or drawing. |
| **R** | **Randomize** | Generates a random initial state across the entire grid. |
| **C** | **Clear** | Wipes the entire grid, removing all living cells. |
| **F** | **Faster** | Increases the simulation speed (FPS) by **+2**. |
| **S** | **Slower** | Decreases the simulation speed (FPS) by **-2** (Min: 5 FPS). |

---

## 🧬 Simulation Rules (The Laws of Nature)

The evolution of the grid is determined by four simple rules. These rules are applied simultaneously to every cell in the grid during each update:

### 1. Underpopulation
Any live cell with **fewer than two** live neighbors dies, as if by underpopulation.

### 2. Survival
Any live cell with **two or three** live neighbors lives on to the next generation.

### 3. Overpopulation
Any live cell with **more than three** live neighbors dies, as if by overpopulation.

### 4. Reproduction
Any dead cell with **exactly three** live neighbors becomes a live cell, as if by reproduction.

### 🔍 Quick Reference Table

| Cell State | Neighbors | Next State | Condition |
| :--- | :--- | :--- | :--- |
| **Live** | < 2 | **Dead** | Underpopulation |
| **Live** | 2 or 3 | **Live** | Survival |
| **Live** | > 3 | **Dead** | Overpopulation |
| **Dead** | 3 | **Live** | Reproduction |

---

## 💡 Tips for Architects
* **Monitor Status:** Check the **Window Title** to see if the simulation is currently "Running" or "Stopped".
* **Experimental Drawing:** Pause the simulation with **SPACE**, use **C** to clear the board, and then draw your custom "seed" patterns (like Gliders or Small Exploders) before hitting **ENTER**.
* **Speed Management:** Use **F** and **S** to find the perfect balance for observing complex evolutions or rapid stability tests. 