#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int lineCounter(char *);

int main ()
{
    char filename[] = "../CMakeLists.txt";
    printf("File contains: %d lines", lineCounter(filename));
    return 0;
}

int lineCounter(char *myFile)
{
    int counter = 0;
    FILE *file = fopen(myFile, "r");
    if (file == NULL) {
        return 0;
    } else {
        char buffer[100];
        while (fgets(buffer, 100, file) != NULL) {
            counter++;
        }
    }
    return counter;
}