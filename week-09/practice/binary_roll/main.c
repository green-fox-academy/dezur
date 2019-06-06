#include <stdio.h>
#include <stdlib.h>

void read_file(char *file);

int main()
{
    read_file("../input.txt");
    return 0;
}

void read_file(char *file)
{
    FILE *myFile = fopen(file, "r");
    char binary[9];
    while (fscanf(myFile, "%s", binary) != EOF) {
        printf("%c", strtol(binary, 0, 2));
    }
    fclose(myFile);
}