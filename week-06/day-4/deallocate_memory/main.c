#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int* pointer = NULL;

    pointer = (int *) malloc(10 * sizeof(int));

    for (int j = 0; j < 5; ++j) {
        pointer[j] = j;
    }

    for (int i = 0; i < 10; ++i) {
        printf("%d", pointer[i]);
    }

    realloc(pointer, 0);

    return 0;
}