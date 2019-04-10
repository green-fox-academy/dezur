#include <iostream>
#include <vector>
#include <algorithm>
#include <SDL.h>


int main() {
    std::vector<std::string> listA {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};
    std::vector<std::string> listB {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};

    // Print out whether List A contains Durian or not
    if (std::find(listA.begin(), listA.end(), "Durian") != listA.end()) {
        std::cout << "List A contains Durian!";
    } else {
        std::cout << "List A does not contain Durian!";
    }

    // Remove Durian from List B
    listB.erase(listB.begin()+4);

    // Add Kiwifruit to List A after the 4th element
    listA.insert(listA.begin()+4, "Kiwifruit");
    return 0;
}