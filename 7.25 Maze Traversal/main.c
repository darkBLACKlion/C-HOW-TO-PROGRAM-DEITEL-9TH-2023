#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 12
#define HEIGHT 12
#define WALL '#'
#define PATH '.'
#define USED_PATH 'X'
#define DIRECTION 4

enum direction {RIGHT, DOWN, LEFT, UP};
const int vertical[DIRECTION] = {0, 1, 0, -1};
const int horizontal[DIRECTION] = {1, 0, -1, 0};

void genereateMaze(char maze[][WIDTH], int *ptrRow, int *ptrCol);
bool isBorder(int row, int col);
void generateExitLocation(int * const ptrRow, int * const ptrCol);
void printMaze(char maze[][WIDTH]);
bool isPath(char maze[][WIDTH], int row, int col);
bool inMaze(int row, int col);
bool canTurnRight(char maze[][WIDTH], int row, int col, enum direction dir);
enum direction canGoForward(char maze[][WIDTH], int row, int col, enum direction dir);
enum direction turnRight(enum direction dir);
enum direction turnLeft(enum direction dir);
enum direction refreshDirection(char maze[][WIDTH], int row, int col, enum direction dir);
void goForward(char maze[][WIDTH], int *ptrRow, int *ptrCol, enum direction dir);
void mazeTraversal(int initialRow, int initialCol, char maze[][WIDTH]);

int main(void) {
    char maze[HEIGHT][WIDTH];
    int initialRow, initialCol;
    
    srand(time(NULL));
    genereateMaze(maze, &initialRow, &initialCol);
    mazeTraversal(initialRow, initialCol, maze);
}

void mazeTraversal(int initialRow, int initialCol, char maze[][WIDTH]) {
    int row = initialRow, col = initialCol;
    enum direction dir = RIGHT;
    
    do {
        maze[row][col] = USED_PATH;
        printMaze(maze);
        dir = refreshDirection(maze, row, col, dir);
        goForward(maze, &row, &col, dir);
    } while (!isBorder(row, col));
    
    if (row == initialRow && col == initialCol) {
        puts("There is no exit");
    }
    else {
        maze[row][col] = USED_PATH;
        printMaze(maze);
        puts("There is an exit and it is found");
    }
}

enum direction refreshDirection(char maze[][WIDTH], int row, int col, enum direction dir) {
    enum direction newDir;
    
    if (canTurnRight(maze, row, col, dir)) {
        newDir = turnRight(dir);
    }
    else {
        newDir = dir;

        while (!canGoForward(maze, row, col, newDir) && newDir != turnRight(dir)) {
            newDir = turnLeft(newDir);
        }
    }
    
    return newDir;
}

void genereateMaze(char maze[][WIDTH], int *ptrRow, int *ptrCol) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (isBorder(row, col)) {
                maze[row][col] = WALL;
            }
            else {
                maze[row][col] = rand() % 2 ? WALL : PATH;
            }
        }
    }
    
    generateExitLocation(ptrRow, ptrCol);
    maze[*ptrRow][*ptrCol] = PATH;
    generateExitLocation(ptrRow, ptrCol);
    maze[*ptrRow][*ptrCol] = PATH;
}

void generateExitLocation(int * const ptrRow, int * const ptrCol) {
    if (rand() % 2) {
        *ptrRow = rand() % 2 ? 0 : HEIGHT - 1;
        *ptrCol = rand() % WIDTH;
    }
    else {
        *ptrCol = rand() % 2 ? 0 : WIDTH - 1;
        *ptrRow = rand() % HEIGHT;
    }
}

void printMaze(char maze[][WIDTH]) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%2c", maze[row][col]);
        }
        puts("");
    }
    puts("");
}

void goForward(char maze[][WIDTH], int *ptrRow, int *ptrCol, enum direction dir) {
    if (canGoForward(maze, *ptrRow, *ptrCol, dir)) {
        *ptrRow += vertical[dir];
        *ptrCol += horizontal[dir];
    }
}

enum direction turnLeft(enum direction dir) {
    return (dir - 1) % DIRECTION;
}

enum direction turnRight(enum direction dir) {
    return (dir + 1) % DIRECTION;
}

bool canTurnRight(char maze[][WIDTH], int row, int col, enum direction dir) {
    dir = (dir + 1) % DIRECTION;
    return canGoForward(maze, row, col, dir);
}

enum direction canGoForward(char maze[][WIDTH], int row, int col, enum direction dir) {
    row += vertical[dir];
    col += horizontal[dir];
    
    return isPath(maze, row, col);
}

bool isPath(char maze[][WIDTH], int row, int col) {
    return inMaze(row, col) &&
        (maze[row][col] == PATH || maze[row][col] == USED_PATH);
}

bool isBorder(int row, int col) {
    return row == 0 || row == HEIGHT - 1 || col == 0 || col == WIDTH - 1;
}

bool inMaze(int row, int col) {
    return row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH;
}
