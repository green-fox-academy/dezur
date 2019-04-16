#include <iostream>
#include <fstream>
#include <string>

int main()
{
    // Create a program that decrypts the file called "reversed-lines.txt",
    // and pritns the decrypred text to the terminal window.

    std::ifstream myFile;
    myFile.open("../reversed-lines.txt");
    std::string text;
    std::string decryptedText;
    while (!myFile.eof()) {
        getline(myFile, text);
        for (int i = text.length()-1; i >= 0; --i) {
            decryptedText += (text.at(i));
        }
        decryptedText += "\n";
    }
    std::cout << decryptedText;
    myFile.close();

    return 0;
}