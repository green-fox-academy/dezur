#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Open a file called "my-file.txt"
    // Write your name in it as a single line
    std::ofstream myFile;
    myFile.open("../my-file.txt");
    if (!myFile.is_open()) {
        std::cout << "Cannot open file!";
        return 0;
    } else {
        myFile << "Petrenyi Zoltan\n";
        myFile.close();
    }

    return 0;
}