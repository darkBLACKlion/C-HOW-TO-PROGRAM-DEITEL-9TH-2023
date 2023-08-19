#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(const char * str);

int main(void) {
    printf("%d\n", isPalindrome(",,   a ad,,,d   a a  "));

}

bool isPalindrome(const char * str) {
    static bool result = true;
    static int mirrorIndex = 0;
    static int currentIndex = 0;
    
    if (str[currentIndex] == '\0') {
        return result = true;
    }

    currentIndex++;
    result = isPalindrome(str);
    currentIndex--;

    if (mirrorIndex >= currentIndex || !result) {
        currentIndex = mirrorIndex = 0;
        return result;
    }
    
    while (isblank(str[mirrorIndex]) || ispunct(str[mirrorIndex])) {
        mirrorIndex++;
    }
    
    if (str[mirrorIndex] == '\0') {
        return result;
    }
    
    while (isblank(str[currentIndex]) || ispunct(str[currentIndex])) {
        currentIndex--;
    }
    
    return str[mirrorIndex++] == str[currentIndex];
}
