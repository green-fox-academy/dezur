#include <iostream>

int main(int argc, char *args[]) {
    std::string username;
    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::cout << "Please enter your username:";

    std::cin >> username;
    std::cout << "Hello " << username;

    return 0;
}