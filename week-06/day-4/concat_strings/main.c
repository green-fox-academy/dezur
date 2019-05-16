#include <stdio.h>
#include <stdlib.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char *concat_strings(char *str1, char *str2);
int str_length(char *str);

int main()
{
    char string1[] = "hehehe\nlkjdglkjsgh.dfnlkdh\njyhdfgkjydsg\tydhdah";
    char string2[] = "hahaha";

    printf("%s", concat_strings(string1, string2));

    return 0;
}

char *concat_strings(char *str1, char *str2)
{
    char *string = (char *) calloc(sizeof(char), str_length(str1) + str_length(str2));

    for (int i = 0; i < str_length(str1); ++i) {
        string[i] = str1[i];
    }
    for (int j = 0; j < str_length(str2); ++j) {
        string[str_length(str1)+j] = str2[j];
    }

    return string;
}

int str_length(char *str)
{
    int counter = 0;

    while (*(str++) != '\0') {
        counter++;
    }
    str -= counter + 1;

    return counter;
}