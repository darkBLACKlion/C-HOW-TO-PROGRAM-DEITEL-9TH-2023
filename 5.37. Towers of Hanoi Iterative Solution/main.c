#include <stdio.h>
#include <math.h>
#define NUMBER_OF_PEGS 3

void towersOfHanoi(int numberOfDisks);
void initializePegs(int numberOfDisks, int pegs[][numberOfDisks]);

int main(void) {
    towersOfHanoi(3);
}

void towersOfHanoi(int numberOfDisks) {
    int pegs[NUMBER_OF_PEGS][numberOfDisks];
    int top[NUMBER_OF_PEGS] = {numberOfDisks - 1, -1, -1};
    int from = 0, to = 1, notUsed = 2;
    
    initializePegs(numberOfDisks, pegs);
    int numberOfMoves = pow(2, numberOfDisks) - 1;
    int movedDesk, temp;
    
    for (int i = 0; i < numberOfMoves; i++) {
        movedDesk = pegs[from][top[from]];
        
        printf("%d\t%d -> %d\n", movedDesk, from, to);
        pegs[to][++top[to]] = pegs[from][top[from]--];
        
        if (movedDesk == 1) {
            temp = notUsed;
            notUsed = to;
            if (top[temp] == -1) {
                to = temp;
            }
            else if(top[from] == -1) {
                to = from;
                from = temp;
            }
            else if (pegs[from][top[from]] < pegs[temp][top[temp]]) {
                to = temp;
            }
            else {
                to = from;
                from = temp;
            }
        }
        else {
            temp = from;
            from = notUsed;
            
            if (movedDesk % 2) {
                notUsed = to;
                to = temp;
            }
            else {
                notUsed = temp;
            }
        }
        
    }
}

void initializePegs(int numberOfDisks, int pegs[][numberOfDisks]) {
    for (int j = 0; j < numberOfDisks; j++) {
        pegs[0][j] = numberOfDisks - j;
    }
}
