#include <stdio.h>
#include <string.h>

void pigLatin(char * sentence);
void printLatinWord(char * word);

int main(void) {
    char sentence[] = "good morning";
    pigLatin(sentence);
}

void pigLatin(char * sentence) {
    char * word = NULL;
    word = strtok(sentence, " ");
    
    while (word) {
        printLatinWord(word);
        printf("%s", " ");
        word = strtok(NULL, " ");
    }
    puts("");
}

void printLatinWord(char * word) {
    if (word != NULL) {
        printf("%s%cay", word + 1, word[0]);
    }
}
