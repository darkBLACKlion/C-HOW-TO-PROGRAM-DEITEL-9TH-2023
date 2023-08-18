#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

const char * const faces[FACES] =
    {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char * const suits[SUITS] =
    {"Heart", "Diamond", "Club", "Spade"};

void reset(int cards[]);
void shuffle(int cards[]);
void deal(int cards[]);

int main(void) {
    srand(time(NULL));
    int cards[CARDS];
    reset(cards);
    shuffle(cards);
    deal(cards);
}

void reset(int cards[]) {
    for (int i = 0; i < CARDS; i++) {
        cards[i] = i;
    }
}

void shuffle(int cards[]) {
    int changeIndex, temp;
    for (int i = 0; i < CARDS; i++) {
        changeIndex = rand() % CARDS;
        temp = cards[i];
        cards[i] = cards[changeIndex];
        cards[changeIndex] = temp;
    }
}

void deal(int cards[]) {
    int suit, face;
    for (int i = 0; i < CARDS; i++) {
        face = cards[i] % FACES;
        suit = cards[i] / FACES;
        printf("%5s of %-8s ", faces[face], suits[suit]);
        
        if ((i + 1) % SUITS == 0) {
            puts("");
        }
    }
}
