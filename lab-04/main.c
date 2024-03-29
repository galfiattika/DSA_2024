#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#include <time.h>
#include <stdlib.h>

int main() {
    IntArray array;
    IntArray array1;

    int commonCount = 0;

    srand(time(NULL));


    createIntArray(5, &array);
    createIntArray(5, &array1);


    for (int i = 0; i < 5; ++i) {
        int random = -20 + rand() % (20 - (-20) + 1);
        insertFirst(&array, random);
    }
    for (int i = 0; i < 5; ++i) {
        int random = -20 + rand() % (20 - (-20) + 1);
        insertFirst(&array1, random);
    }
    for (int i = 0; i < 5; ++i) {
        if (search(array1, array.elements[i]) != -1) {
            commonCount++;
        }
    }
    printArray(array);
    printArray(array1);
    printf("\nThe number of common elements in the arrays: %d\n", commonCount);
}
