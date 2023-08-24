#include <stdio.h>
#include <string.h>

void printWordsReverse(char * str);

int main(void) {
    char string[] = "Merhabalar Muhammet Yusuf Karaaslan\n";
    printWordsReverse(string);
}

void printWordsReverse(char * str) {
    char * word = strtok(str, " \n\t");
    if (word == NULL) {
        return;
    }
    printWordsReverse(NULL);
    printf("%s ", word);
}
