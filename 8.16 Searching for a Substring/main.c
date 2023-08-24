#include <stdio.h>
#include <string.h>

void substrings(char * str, char * substr);

int main(void) {
    substrings("sabah bir başka, sabah aydınlık, sabah serin", "sabah");
}

void substrings(char * str, char * substr) {
    for (char * temp = str; temp = strstr(temp, substr); temp++) {
        printf("%s\n", temp);
    }
}
