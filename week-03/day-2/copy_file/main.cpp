#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copyFile(std::string, std::string);

int main()
{
    if (copyFile("../file1.txt", "../file2.txt") == 1){
        std::cout << "Copy was successful";
    } else {
        std::cout << "Failed to copy file";
    }
    return 0;
}

bool copyFile(std::string originalFile, std::string copiedFile)
{
    std::string line;
    std::ifstream file1;
    std::ofstream file2;
    file1.open(originalFile);
    file2.open(copiedFile);
    if (file1.is_open() && file2.is_open() == 1) {
        while (!file1.eof()) {
            getline(file1, line);
            file2 << line << std::endl;
        }
        file1.close();
        file2.close();
        return 1;
    }
    return 0;
}