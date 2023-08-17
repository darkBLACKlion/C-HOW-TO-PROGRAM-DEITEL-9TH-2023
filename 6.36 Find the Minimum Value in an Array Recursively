#include <stdio.h>
#define SIZE 7

int minimum(int array[], size_t size);

int main(void) {
    int array[SIZE] = {9, -5, -12, 77, -245, 0, 345};
    printf("%d\n", minimum(array, SIZE));
}

int minimum(int array[], size_t size) {
    // It is assumed that array has more than 0 element
    static int min; // No need to use auto
    
    if (size == 1) {
        return array[0];
    }
    
    min = minimum(array, size - 1);
    
    if (min > array[size - 1]) {
        min = array[size - 1];
    }
    
    return min;
}
