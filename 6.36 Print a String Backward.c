#include <stdio.h>

void printBackward(char string[]);

int main(void) {
    char string[] = "Muhammet Yusuf Karaaslan";
    printBackward(string);
    puts("");
}

void printBackward(char string[]) {
    static size_t index = 0;
    
    if (string[index] == '\0') {
        return;
    }
    index++;
    printBackward(string);
    index--;
    printf("%c", string[index]);
}
