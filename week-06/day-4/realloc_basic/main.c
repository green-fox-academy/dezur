#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int *pointer = NULL;
    int *pointer2 = NULL;
    int x, y = 0, num;

    printf("Enter a number\n");
    scanf("%d", &x);

    pointer = (int *) malloc(x * sizeof(int));

    for (int i = 0; i < x; ++i) {
        printf("Enter %d. number\n", i + 1);
        scanf("%d", &num);
        pointer[i] = num;
        y += num;
    }

    pointer2 = (int *) malloc(y * sizeof(int));

    for (int j = 0; j < y; ++j) {
        pointer2[j] = j + 1;
    }

    for (int k = 0; k < y; ++k) {
        printf("%d ", pointer2[k]);
    }
    return 0;
}