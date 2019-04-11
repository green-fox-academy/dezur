#include <iostream>
#include <string>

int counter = 0;

std::string changeLetter(std::string);

int main()
{
    std::string word = "extra";
    std::cout << changeLetter(word);

    return 0;
}

std::string changeLetter(std::string hinyje)
{

    if (counter == hinyje.length()) {
        return hinyje;
    } else {
        if (hinyje[counter] == 'x') {
            hinyje[counter] = 'y';
        }
        counter++;
        return changeLetter(hinyje);
    }
}