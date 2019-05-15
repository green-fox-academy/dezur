#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer1;
    computer1.cpu_speed_GHz = 1.8;
    computer1.ram_size_GB = 4;
    computer1.bits = 64;

    Notebook notebook1;
    notebook1.cpu_speed_GHz = 2.4;
    notebook1.ram_size_GB = 8;
    notebook1.bits = 64;

    printf("The computer have %.1fGHz %dbit processor and %dGB memory.\n", computer1.cpu_speed_GHz, computer1.bits, computer1.ram_size_GB);
    printf("The notebook have %.1fGhz %dbit processor and %dGB memory.\n", notebook1.cpu_speed_GHz, notebook1.bits, notebook1.ram_size_GB);

    return 0;
}