 Maze Generator (C)

## Overview

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
