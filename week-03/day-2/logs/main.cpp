#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

std::vector<std::string> uniqueIP(std::string);
float getPostRatio(std::string);

int main()
{
    std::vector<std::string> unique = uniqueIP("../log.txt");
    for (int i = 0; i < unique.size(); ++i) {
        std::cout << unique[i] << std::endl;
    }
    std::cout << "GET/POST ratio: " << getPostRatio("../log.txt") << std::endl;
    return 0;
}

std::vector<std::string> uniqueIP(std::string logFile)
{
    std::vector<std::string> v;

    // Filling vector with IP addresses
    std::ifstream infile(logFile);
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string token;
        int counter = 0;
        while (std::getline(ss, token, ' ')) {
            counter++;
            if (counter == 9) {
                v.push_back(token);
            }
        }
    }
    // Removing multiple elements from vector
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());

    return v;
}

float getPostRatio(std::string logFile)
{
    std::ifstream infile(logFile);
    std::string line;
    float getCounter = 0;
    float postCounter = 0;
    while (std::getline(infile, line)) {
        std::istringstream ss(line);
        std::string token;
        int counter = 0;
        while (std::getline(ss, token, ' ')) {
            counter++;
            if (counter == 12) {
                if (token == "GET") {
                    getCounter++;
                } else
                    postCounter++;
            }
        }
    }

    return getCounter / postCounter;
}