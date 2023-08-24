#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printTelephoneNumber(char * str);

int main(void) {
    char number[] = "(544) 699 6991";
    printTelephoneNumber(number);
}

void printTelephoneNumber(char * str) {
    char * str1 = strtok(str, ",( ");
    char * str2 = strtok(NULL, ",( ");
    char * str3 = strtok(NULL, ",( ");
    
    char * ptr;
    long areaCode = strtol(str1, &ptr, 10);
    long first3digit = strtol(str2, &ptr, 10);
    long last4digit = strtol(str3, &ptr, 10);
    
    printf("%ld %ld %ld\n", areaCode, first3digit, last4digit);
}
