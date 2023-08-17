#include <stdio.h>
#define SIZE 5

int binarySearch(int array[], int firstIndex, int lastIndex, int key);

int main(void) {
    int array[SIZE] = {1, 2, 3, 4, 5};
    
    printf("%d\n", binarySearch(array, 0, SIZE - 1, 9));
}

int binarySearch(int array[], int firstIndex, int lastIndex, int key) {
    if (firstIndex > lastIndex) {
        return -1;
    }
    
    int middle = (firstIndex + lastIndex) / 2;
    
    if (array[middle] == key) {
        return middle;
    }
    else if (key < array[middle]){
        return binarySearch(array, firstIndex, middle - 1, key);
    }
    else {
        return binarySearch(array, middle + 1, lastIndex, key);
    }
}
