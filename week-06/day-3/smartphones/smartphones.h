//
// Created by Zoli on 2019. 06. 06..
//

#ifndef SMARTPHONES_SMARTPHONES_H
#define SMARTPHONES_SMARTPHONES_H

#endif //SMARTPHONES_SMARTPHONES_H

typedef enum
{
    SMALL, MEDIUM, BIG
} screen;

typedef struct
{
    char *name;
    screen screen_size;
    int release_year;
} smartphones_t;

smartphones_t *smartphones;

void read_file(char *);
void write_file(char *);
char *get_oldest_phone();
int get_screen_size_count(screen);