#include <stdio.h>

// size of the maze is M rows and N columns
const int M = 6;
const int N = 5;

// Goal: Start from (0,0) and reach (M-1, N-1)

// design of the maze (1 = blocked and 0 = safe for passage)
int maze[M][N] = {
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {1, 0, 0, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 1, 0}
};

int solution[M][N] = {0};  // solution 

// 4 directions to move (down, up, right, left)
int x_del[] = {1, 0, 0, -1};
int y_del[] = {0, 1, -1, 0};

// Check if current position is within range and allowed
int is_safe(int row, int col) {
    int ret;

    ret = ((row >= 0) && (row < M) && (col >= 0) && (col < N) \
            && (maze[row][col] == 0) && (solution[row][col] == 0));
    return ret;
}

// Recursive function to solve the maze
int solve_maze(int x, int y) {
    int i, r;

    // if reached the destination, mark it and return success
    if ((x == M-1) && (y == N-1) && (maze[x][y] == 0)) {
        solution[x][y] = 1;
        return 1;
    }

    // Check if current location is safe. If yes then move ahead
    if (is_safe(x, y)) {
        solution[x][y] = 1;  // Mark current cell as part of the path

        // Try all four possible directions
        for (i = 0; i < 4; i++) {
            r = solve_maze(x+x_del[i], y+y_del[i]);
            if(r==1) 
                return 1;
        }

        // all 4 directions tried. If we are here then none of them worked
        // Therefore backtrack after marking current position 0 again
        solution[x][y] = 0;
    }
    return 0;
}

// print the original maze
void print_maze() {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ", maze[i][j]);
        }
        printf("\n");
    }
}

// print the solution 
void print_solution() {
    int i, j;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%3d ",solution[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (solve_maze(0, 0)==1) {
        printf("Original maze is\n");
        print_maze();

        printf("Solution:\n");
        print_solution();
    } else {
        printf("No solution found\n");
    }
    return 0;
}

