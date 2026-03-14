 Maze Generator (C)

## Overview

This is a group project.
This project generates a maze using the Randomized Depth-First Search (DFS) algorithm.  
The program takes the dimensions of the maze as input at runtime and generates a random maze accordingly.

All instructions and inputs are requested interactively when the compiled C executable is run.

## Algorithm

The maze is generated using Randomized Depth-First Search:

1. Start from a random cell.
2. Mark the cell as visited.
3. Randomly choose an unvisited neighboring cell.
4. Remove the wall between the current cell and the chosen neighbor.
5. Recursively repeat the process.
6. Backtrack when no unvisited neighbors remain.

This algorithm ensures the maze is fully connected and acyclic.

## For Maze_solver.c

I also wrote a standalone maze generation and solving program.
This program is a C-based maze solver that uses a recursive backtracking algorithm to find a path from the starting position to a specific goal.

The code simulates navigating a 2D grid where the objective is to travel from the top-left corner (0, 0) to the bottom-right corner (M-1, N-1). It explores possible routes and backtracks when it hits a dead end.

The maze is hardcoded as a 6x5 matrix. A 0 represents a safe passage, while a 1 represents a blocked path (wall).

Backtracking Logic: It marks its current path in a separate solution matrix. If a chosen direction leads to a blocked cell or a dead end, the program unmarks the current cell and steps back to try an alternative route.

Outputs: Upon execution, if a valid path exists, the program prints both the original maze layout and the final solution matrix (where 1 indicates the successful path). If the destination is unreachable, it outputs "No solution found."
