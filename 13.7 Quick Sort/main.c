void quickSort(int array[], int size) {
    int partition(int array[], int size);
    
    if (size <= 1) {
        return;
    }
    
    int middle = partition(array, size);
    quickSort(array, middle);
    quickSort(array + middle + 1, size - middle - 1);
}

int partition(int array[], int size) {
    void swap(int* num1, int* num2);
    
    int index = 0;
    int compareIndex = size - 1;

    while (compareIndex != index) {
        while (compareIndex > index && array[compareIndex] >= array[index]) {
            compareIndex--;
        }
            
        while (compareIndex < index && array[compareIndex] <= array[index]) {
            compareIndex++;
        }
            
        swap(&array[compareIndex], &array[index]);
    }
    
    return index;
}
