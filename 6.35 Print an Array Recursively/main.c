#include <stdio.h>
#define SIZE 7

void printArray(int array[], size_t size);


int main(void) {
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7};
    printArray(array, SIZE);
    puts("");
}

void printArray(int array[], size_t size) {
    static size_t index = 0;
    
    if (size == 0) {
        return;
    }
    
    printf("%d\t", array[index]);
    index++;
    printArray(array, size - 1);
    index--;
}
