#include <iostream>
#include <fstream>
#include <string>

int countLines(std::string);

int main()
{
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file
    std::cout << "The file contains " << countLines("../my-file.txt") << " lines.\n";
    return 0;
}

int countLines(std::string fileName)
{
    int counter = 0;
    std::ifstream myFile;
    myFile.open(fileName);
    if (!myFile.is_open()) {
        return 0;
    } else {
        std::string text;
        while (!myFile.eof()) {
            getline(myFile, text);
            counter++;
        }
        return counter;
    }
}