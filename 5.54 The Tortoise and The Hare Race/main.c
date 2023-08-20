#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startRace(void);
int moveTortoise(int tortoise, int finish);
int moveHare(int hare, int finish);
void startMessage(void);
void printRaceCourse(int hare, int tortoise, int finish);
int clip(int number, int min, int max);
void printResult(int hare, int tortoise);

int main(void) {
    srand(time(NULL));
    startRace();
}

void startRace(void) {
    int hare = 1;
    int tortoise = 1;
    int finish = 70;
    startMessage();
    
    long int tick = time(NULL);
    
    puts("");
    printRaceCourse(hare, tortoise, finish);
    
    while (hare < finish && tortoise < finish) {
        hare = moveHare(hare, finish);
        tortoise = moveTortoise(tortoise, finish);
        
        while (tick == time(NULL));
        tick = time(NULL);
        
        puts("");
        printRaceCourse(hare, tortoise, finish);
    }
    
    puts("");
    printResult(hare, tortoise);
}

void printResult(int hare, int tortoise) {
    if (hare > tortoise) {
        puts("Hare wins. Yuch.");
    }
    else if (tortoise > hare){
        puts("TORTOISE WINS!!! YAY!!!");
    }
    else {
        puts("It is a tie.");
    }
}

void printRaceCourse(int hare, int tortoise, int finish) {
    for (int i = 1; i <= finish; i++) {
        printf("_");
    }
    
    puts("");
    
    for (int i = 1; i <= finish; i++) {
        if (tortoise == i && tortoise == hare) {
            printf("%s", "OUCH!!!");
        }
        else if (tortoise == i) {
            printf("%c", 'T');
        }
        else if (hare == i) {
            printf("%c", 'H');
        }
        else {
            printf(" ");
        }
    }
}

int moveTortoise(int tortoise, int finish) {
    int number = rand() % 10 + 1;
    int move;
    
    if (number <= 5) {
        move = 3;
    }
    else if (number <= 7) {
        move = -6;
    }
    else {
        move = 1;
    }
    
    tortoise += move;
    return clip(tortoise, 1, finish);
}

int moveHare(int hare, int finish) {
    int number = rand() % 10 + 1;
    int move;
    
    if (number <= 2) {
        move = 0;
    }
    else if (number <= 4) {
        move = 9;
    }
    else if (number <= 5) {
        move = -12;
    }
    else if (number <= 8) {
        move = 1;
    }
    else {
        move = -2;
    }
    
    hare += move;
    return clip(hare, 1, finish);
}

void startMessage(void) {
    puts("ON YOUR MARK, GET SET");
    puts("BANG             !!!!");
    puts("AND THEY'RE OFF  !!!!");
}

int clip(int number, int min, int max) {
    if (number > max) {
        return max;
    }
    else if (number < min) {
        return min;
    }
    
    return number;
}
