#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // Create a program that writes this line 100 times:
    // "I won't cheat on the exam!"
    int i = 0;
    while(i < 100) {
        std::cout << "I won't cheat on the exam!\n";
        i++;
    }

    return 0;
}