#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define QUEEN -1

unsigned long long int queenProblem(const int size, int board[][size], int row);
int whereIsQueen(const int row[], const int size);
void putQueen(const int size, int board[][size], const int row, const int col, const int number1, const int number2);
void printBoard(const int size, const int board[][size]);
void initializeBoard(const int size, int board[][size]);
bool isBoardEmpty(int size, int board[][size], int row);

int main(void) {
    int lengthOfChessBoard = 8;

    int board[lengthOfChessBoard][lengthOfChessBoard];
    initializeBoard(lengthOfChessBoard, board);
    printf("%d X %d chess board has %llu total solutions for queen problem\n",
           lengthOfChessBoard, lengthOfChessBoard, queenProblem(lengthOfChessBoard, board, 0));
}

unsigned long long int queenProblem(const int size, int board[][size], int row) {
    static unsigned long long int numberOfSolution = 0;

    if (row == size) {
        return ++numberOfSolution;
    }
    
    for (int col = 0; col < size; col++) {
        if (board[row][col] == 0) {
            putQueen(size, board, row, col, QUEEN, 1);
            queenProblem(size, board, row + 1);
            putQueen(size, board, row, col, 0, -1);
        }
    }
    
    if (row == 0) {
        unsigned long long int temp = numberOfSolution;
        numberOfSolution = 0;
        return temp;
    }
    
    return numberOfSolution;
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

bool isBoardEmpty(int size, int board[][size], int row) {
    bool isEmpty = true;;
    
    for (int i = row; i < size && isEmpty; i++) {
        isEmpty = false;
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                isEmpty = true;
                break;
            }
        }
    }
    
    return isEmpty;
}
