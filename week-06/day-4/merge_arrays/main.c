#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int *pointer = NULL;
    int *pointer2 = NULL;

    pointer = (int *) malloc(10 * sizeof(int));
    pointer2 = (int *) malloc(10 * sizeof(int));

    for (int i = 0; i < 10; ++i) {
        pointer[i] = i * 2;
        pointer2[i] = i * 2 + 1;
    }

    pointer = (int *) realloc(pointer, 20 * sizeof(int));

    for (int k = 0; k < 10; ++k) {
        pointer[k+10] = pointer2[k];
    }

    for (int l = 9; l > -1; --l) {
        printf("%d %d ", pointer[l+10], pointer[l]);
    }

    free(pointer);
    pointer = NULL;
    free(pointer2);
    pointer2 = NULL;


    return 0;
}