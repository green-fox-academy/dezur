#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartphones.h"

int main()
{
    read_file("../phones.txt");
    printf("The %s is the oldest device in the database.\n", get_oldest_phone());
    printf("There are %d phones with BIG (>= 15 cm) screen size\n", get_screen_size_count(BIG));
    printf("There are %d phones with SMALL (< 12 cm) screen size\n", get_screen_size_count(SMALL));
    write_file("../prices.txt");
    free(smartphones);
    return 0;
}