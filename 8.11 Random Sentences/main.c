#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define ARTICLES 5
#define NOUNS 5
#define VERBS 5
#define PREPOSITIONS 5
#define SIZE 100

char * article[ARTICLES] = {"the", "a", "one", "some", "any"};
char * noun[NOUNS] = {"boy", "girl", "dog", "town", "car"};
char * verb[VERBS] = {"drove", "jumped", "ran", "walked", "skipped"};
char * preposition[PREPOSITIONS] = {"to", "from", "over", "under", "on"};

char * pickRandomArticle(void);
char * pickRandomVerb(void);
char * pickRandomNoun(void);
char * pickRandomPreposition(void);
void printRandomSentence(void);

int main(void) {
    srand(time(NULL));
    
    for (int i = 1; i <= 10; i++) {
        printRandomSentence();
    }
}

void printRandomSentence(void) {
    char sentence[100] = "";
    
    strcat(sentence, pickRandomArticle());
    strcat(sentence, " ");
    strcat(sentence, pickRandomNoun());
    strcat(sentence, " ");
    strcat(sentence, pickRandomVerb());
    strcat(sentence, " ");
    strcat(sentence, pickRandomPreposition());
    strcat(sentence, " ");
    strcat(sentence, pickRandomArticle());
    strcat(sentence, " ");
    strcat(sentence, pickRandomNoun());
    
    strcat(sentence, ".");
    sentence[0] = toupper(sentence[0]);
    
    puts(sentence);
}

char * pickRandomArticle(void) {
    return article[rand() % ARTICLES];
}

char * pickRandomVerb(void) {
    return verb[rand() % VERBS];
}

char * pickRandomNoun(void) {
    return noun[rand() % NOUNS];
}

char * pickRandomPreposition(void) {
    return preposition[rand() % PREPOSITIONS];
}
