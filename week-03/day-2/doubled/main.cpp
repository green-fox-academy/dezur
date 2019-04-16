#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Create a program that decrypts the file called "duplicated-chars.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream myFile;
    myFile.open("../duplicated-chars.txt");
    std::string text;
    std::string decryptedText;
    while (!myFile.eof()) {
        getline(myFile, text);
        for (int i = 0; i < text.length(); ++i) {
            if (i % 2 == 0) {
                decryptedText += (text.at(i));
            }
        }
        decryptedText += "\n";
    }
    std::cout << decryptedText;
    myFile.close();

    return 0;
}