#include <stdio.h>
#define SIZE 5

int linearSearch(int array[], int size, int key);

int main(void) {
    int array[SIZE] = {1, 2, 3, 4, 5};
    
    printf("%d\n", linearSearch(array, SIZE, 2));
}

int linearSearch(int array[], int size, int key) {
    if (size == 0) {
        return -1;
    }
    else if (key == array[size - 1]) {
        return size - 1;
    }
    else {
        return linearSearch(array, size - 1, key);
    }
}

