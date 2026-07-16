# CSES - Monsters

## Description

Given a labyrinth containing walls (`#`), empty cells (`.`), one player (`A`), and several monsters (`M`), determine whether the player can escape by reaching any boundary cell before a monster can reach the same cell.

Both the player and every monster move simultaneously, one cell per step, in one of four directions (up, down, left, right).

If an escape is possible, output one valid path.

---

## Algorithm

### 1. Multi-source BFS for Monsters

All monster positions are pushed into the queue initially.

A breadth-first search computes the minimum time required for any monster to reach every reachable cell.

`step[i][j]` stores the earliest time a monster can arrive at cell `(i, j)`.

---

### 2. BFS for the Player

Run another BFS starting from the player's position.

The player is only allowed to move into a neighboring cell if

```cpp
moving[cur] + 1 < step[next]
```

where

* `moving[][]` is the player's arrival time.
* `step[][]` is the monster's arrival time.

The strict inequality is necessary because arriving at the same time as a monster is not safe.

During the search, store

* `parent[][]` for path reconstruction.
* `path[][]` for the direction used to reach each cell.

The search stops immediately after reaching any boundary cell.

---

### 3. Path Reconstruction

Starting from the escape cell, repeatedly follow the `parent` array until reaching the starting position.

The collected directions are obtained in reverse order, so the final path is reversed before printing.

---

## Correctness

### Monster BFS

Because BFS explores vertices level by level, the first time a cell is visited is the earliest possible arrival time for any monster.

Starting the BFS from every monster simultaneously guarantees that `step[][]` contains the minimum monster arrival time for every reachable cell.

### Player BFS

The player only enters cells where

```
player_time < monster_time
```

Therefore, the player never occupies a cell simultaneously with a monster.

Since BFS explores states in increasing order of distance, the first boundary cell reached corresponds to a shortest valid escape path.

---

## Complexity

* **Time Complexity:** `O(n × m)`
* **Memory Complexity:** `O(n × m)`

Both BFS traversals visit each cell at most once.

---

## Data Structures

| Variable      | Purpose                               |
| ------------- | ------------------------------------- |
| `step[][]`    | Earliest arrival time of monsters     |
| `moving[][]`  | Player's arrival time                 |
| `visited[][]` | Marks visited cells during BFS        |
| `parent[][]`  | Previous cell for path reconstruction |
| `path[][]`    | Direction used to reach each cell     |

---

## Key Idea

The solution separates the problem into two independent shortest-path computations:

1. Compute the earliest arrival time of every monster using **Multi-source BFS**.
2. Perform another BFS for the player while only moving into cells that are guaranteed to be reached before any monster.

This guarantees both correctness and an optimal time complexity of **O(n × m)**, making the solution suitable for grids up to **1000 × 1000**.
