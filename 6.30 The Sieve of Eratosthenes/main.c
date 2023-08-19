#include <stdio.h>
#include <stdbool.h>
#define SIZE 100000

void sieveEratosthenes(void);

int main(void) {
    sieveEratosthenes();
}

void sieveEratosthenes(void) {
    static bool isComposite[SIZE] = {true, true, false};

    for (size_t number = 2, numberOfPrime = 0; number < SIZE; number++) {
        if (!isComposite[number]) {
            printf("%5zu)%5zu\n", ++numberOfPrime, number);
            
            for (size_t i = number * 2; i < SIZE; i += number) {
                isComposite[i] = true;
            }
        }
    }
}
