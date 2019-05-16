#include <stdio.h>
#include <stdlib.h>

// with calloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits
// what's the difference between this and the previous excersice?

int main()
{
    int* pointer = NULL;

    pointer = (int *) calloc(sizeof(int), 10);

    for (int j = 0; j < 5; ++j) {
        pointer[j] = j;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d", pointer[i]);
    }

    free(pointer);
    pointer = NULL;

    return 0;
}