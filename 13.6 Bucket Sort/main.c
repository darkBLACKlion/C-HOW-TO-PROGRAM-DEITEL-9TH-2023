void bucketSort(int array[], int size) {
    bool copyToBucket(int array[], int size, int bucket[][size + 1], int digit, unsigned int divide);
    void copyFromBucket(int array[], int size, int bucket[][size + 1], int digit);
    
    int digit = 10;
    int bucket[digit][size + 1];
    memset(bucket, 0, sizeof(int) * (size + 1) * digit);
    
    for (unsigned int divide = 1; !copyToBucket(array, size, bucket, digit, divide); divide *= digit) {
        copyFromBucket(array, size, bucket, digit);
    }
}

void copyFromBucket(int array[], int size, int bucket[][size + 1], int digit) {
    for (int row = 0, i = 0; row < digit; row++) {
        for (int col = 0; col < bucket[row][size]; col++) {
            array[i++] = bucket[row][col];
        }
        bucket[row][size] = 0;
    }
}

bool copyToBucket(int array[], int size, int bucket[][size + 1], int digit, unsigned int divide) {
    bool finish = true;
    
    for (int i = 0, row, col; i < size; i++) {
        row = array[i] / divide % digit;
        
        if (row) {
            finish = false;
        }
        
        col = bucket[row][size]++;
        bucket[row][col] = array[i];
    }
    
    return finish;
}
