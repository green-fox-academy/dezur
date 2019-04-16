#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
    // Create a program that decrypts the file called "reversed-order.txt",
    // and pritns the decrypred text to the terminal window.

    std::vector<std::string> lines;
    std::ifstream myFile;
    myFile.open("../reversed-order.txt");
    std::string text;
    std::string decryptedText;
    while (!myFile.eof()) {
        getline(myFile, text);
        lines.push_back(text);
    }
    for (int i = lines.size(); i >= 0; --i) {
        std::cout << lines[i] << std::endl;
    }
}