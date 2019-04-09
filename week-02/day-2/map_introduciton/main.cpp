#include <iostream>
#include <map>

int main() {
    // Create an empty map where the keys are integers and the values are characters
    std::map<int, char> myMap;

    // Print out whether the map is empty or not
    if (myMap.empty() == true) {
        std::cout << "The map is empty\n";
    } else {
        std::cout << "The map is not empty\n";
    }

    // Add the following key-value pairs to the map
    myMap.insert(std::make_pair(97, 'a'));
    myMap.insert(std::make_pair(98, 'b'));
    myMap.insert(std::make_pair(99, 'c'));
    myMap.insert(std::make_pair(65, 'A'));
    myMap.insert(std::make_pair(66, 'B'));
    myMap.insert(std::make_pair(67, 'C'));

    // Print all the keys
    std::map<int, char>::iterator mapIterator;
    for (mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        std::cout << mapIterator->first << std::endl;
    }

    // Print all the values
    for (mapIterator = myMap.begin(); mapIterator != myMap.end(); mapIterator++) {
        std::cout << mapIterator->second << std::endl;
    }

    // Add value D with the key 68
    myMap.insert(std::make_pair(68, 'D'));

    // Print how many key-value pairs are in the map
    std::cout << myMap.size() << std::endl;

    // Print the value that is associated with key 99
    std::cout << myMap[99] << std::endl;

    // Remove the key-value pair where with key 97
    myMap.erase(97);

    // Print whether there is an associated value with key 100 or not
    if (myMap.find(100) == myMap.end()) {
        std::cout << "Key 100 doesn't have associated value!";
    } else {
        std::cout << myMap[100];
    }

    // Remove all the key-value pairs
    myMap.clear();

    return 0;
}