#include <stdio.h>
#include <stdbool.h>
#define QUEEN -1

unsigned long long int queenProblem(const int size);
int whereIsQueen(const int row[], const int size);
void putQueen(const int size, int board[][size], const int row, const int col, const int number1, const int number2);
void printBoard(const int size, const int board[][size]);
void initializeBoard(const int size, int board[][size]);

int main(void) {
    int lengthOfChessBoard = 14;
    printf("%d X %d chess board has %llu total solutions for queen problem\n",
           lengthOfChessBoard, lengthOfChessBoard, queenProblem(lengthOfChessBoard));
}

unsigned long long int queenProblem(const int size) {
    unsigned long long int numberOfDifferentBoard = 0;
    int board[size][size];
    initializeBoard(size, board);
    
    int row = 0;
    int col = 0;
    
    while(row != -1) {
        if (row == size) {
            numberOfDifferentBoard++;
            //printBoard(size, board);
            row--;
        }
        
        col = whereIsQueen(board[row], size);
        
        if (col != -1) {
            putQueen(size, board, row, col, 0, -1);
        }
        
        while (++col < size) {
            if (board[row][col] == 0) {
                putQueen(size, board, row, col, QUEEN, 1);
                row++;
                break;
            }
        }
        
        if (col == size) {
            row--;
        }
    }
    
    return numberOfDifferentBoard;
}

int whereIsQueen(const int row[], const int size) {
    for (int i = 0; i < size; i++) {
        if (row[i] == QUEEN) {
            return i;
        }
    }
    
    return -1;
}

void putQueen(const int size, int board[][size], const int row, const int col, const int num1, const int num2) {
    board[row][col] = num1;
    
    for (int i = row + 1; i < size; i++) {
        board[i][col] += num2;
    }
    
    for (int i = row + 1, j = col - 1; i < size && j >= 0; i++, j--) {
        board[i][j] += num2;
    }
    
    for (int i = row+1, j = col + 1; i < size && j < size; i++, j++) {
        board[i][j] += num2;
    }
}

void printBoard(const int size, const int board[][size]) {
    static unsigned long long int numberOfBoard = 1;
    printf("\n\n\n%llu)\n", numberOfBoard++);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%c ", board[i][j] == QUEEN ? 'Q' : '-');
        }
        
        puts("");
    }
}

void initializeBoard(const int size, int board[][size]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = 0;
        }
    }
}
