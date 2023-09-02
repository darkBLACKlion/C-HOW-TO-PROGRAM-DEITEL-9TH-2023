#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define SIDE 8
#define MOVE 8
#define DIMENSION 2

int board[SIDE][SIDE] = {0};
int accessBoard[SIDE][SIDE];
const int horizontal[MOVE] = {2, 1, -1, -2, -2, -1, 1, 2};
const int vertical[MOVE] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool inBoard(int row, int col);
void printBoard(void);
bool canBeMoved(int row, int col);
void resetAccess(void);
bool refreshAccess(int currentRow, int currentCol, int next, bool forward);
void knightTour(int currentRow, int currentCol, int next);

int main(void) {
    resetAccess();
    
    for (int row = 0; row < SIDE; row++) {
        for (int col = 0; col < SIDE; col++) {
            knightTour(row, col, 1);
        }
    }
    
}

void knightTour(int currentRow, int currentCol, int next) {
    if (!canBeMoved(currentRow, currentCol)) {
        return;
    }
    
    board[currentRow][currentCol] = next;
    if (next == SIDE * SIDE) {
        printBoard();
    }
    
    if (refreshAccess(currentRow, currentCol, next + 1, true)) {
        for (int move = 0; move < MOVE; move++) {
            knightTour(currentRow + vertical[move], currentCol + horizontal[move], next + 1);
        }
    }
    
    board[currentRow][currentCol] = 0;
    refreshAccess(currentRow, currentCol, next + 1, false);
}

bool canBeMoved(int row, int col) {
    return inBoard(row, col) && board[row][col] == 0;
}

bool inBoard(int row, int col) {
    return row >= 0 && row < SIDE &&
        col >= 0 && col < SIDE;
}

void printBoard(void) {
    static int numberOfKnightsTour = 0;
    
    printf("%d)\n", ++numberOfKnightsTour);
    
    for (int row = 0; row < SIDE; row++) {
        for (int col = 0; col < SIDE; col++) {
            printf("%4d", board[row][col]);
        }
        puts("");
    }
    
    puts("");
}

void resetAccess(void) {
    for (int row = 0; row < SIDE; row++) {
        for (int col = 0; col < SIDE; col++) {
            accessBoard[row][col] = 0;
            
            for (int move = 0; move < MOVE; move++) {
                if (inBoard(row + vertical[move] , col + horizontal[move])) {
                    ++accessBoard[row][col];
                }
            }
        }
    }
}

bool refreshAccess(int currentRow, int currentCol, int next, bool forward) {
    int row, col;
    bool result = true;
    
    for (int move = 0; move < MOVE; move++) {
        row = currentRow + vertical[move];
        col = currentCol + horizontal[move];
        
        if (inBoard(row, col)) {
            forward ? --accessBoard[row][col] : ++accessBoard[row][col];
            
            if (accessBoard[row][col] == 0 && board[row][col] == 0 && next != SIDE * SIDE) {
                result = false;
            }
        }
    }
    
    return result;
}
