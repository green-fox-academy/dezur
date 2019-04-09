#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> myList;

    std::cout << myList.size() << std::endl;
    myList.push_back("William");
    if (myList.empty() == true) {
        std::cout << "The list is empty\n";
    } else {
        std::cout << "The list is not empty\n";
    }

    myList.push_back("John");

    myList.push_back("Amanda");

    std::cout << myList.size() << std::endl;

    std::cout << myList[2] << std::endl;

    for (std::vector<std::string>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << std::endl;
    }

    for (std::vector<std::string>::iterator it2 = myList.begin(); it2 != myList.end(); ++it2) {
        std::cout << std::distance(myList.begin(), it2) + 1 << ". " << *it2 << std::endl;
    }

    myList.erase(myList.begin() + 1);

    for (std::vector<std::string>::iterator it3 = myList.end()-1; it3 >= myList.begin(); --it3) {
        std::cout << *it3 << std::endl;
    }

    myList.clear();

    return 0;
}