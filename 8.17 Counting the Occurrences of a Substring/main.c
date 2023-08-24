#include <stdio.h>
#include <string.h>

int substrings(char * str, char * substr);

int main(void) {
    printf("%d\n", substrings("sabah bir başka, sabah aydınlık, sabah serin", "sabah"));
}

int substrings(char * str, char * substr) {
    int result = 0;
    for (char * temp = str; temp = strstr(temp, substr); temp++) {
        result++;
    }
    
    return result;
}
