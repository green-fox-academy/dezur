#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char *args[]) {

    double a = 24;
    int out = 0;
    // if a is even increment out by one
    if (std::fmod(a, 2) == 0) {
        out += 1;
    }

    std::cout << out << std::endl;


    int b = 13;
    std::string out2 = "";
    // if b is between 10 and 20 set out2 to "Sweet!"
    // if less than 10 set out2 to "Less!",
    // if more than 20 set out2 to "More!"
    if (b >= 10 && b <= 20) {
        out2 = "Sweet!";
    } else if (b < 10) {
        out2 = "Less!";
    } else if (b > 20) {
        out2 = "More!";
    }


    std::cout << out2 << std::endl;


    int c = 123;
    int credits = 100;
    bool isBonus = false;
    // if credits are at least 50,
    // and isBonus is false decrement c by 2
    // if credits are smaller than 50,
    // and isBonus is false decrement c by 1
    // if isBonus is true c should remain the same

    if (isBonus == false) {
        if (credits >= 50) {
            c -= 2;
        } else if (credits < 50) {
            c -= 1;
        }
    }

    std::cout << c << std::endl;


    int d = 8;
    int time = 120;
    std::string out3 = "";
    // if d is dividable by 4
    // and time is not more than 200
    // set out3 to "check"
    // if time is more than 200
    // set out3 to "Time out"
    // otherwise set out3 to "Run Forest Run!"

    if (d%4 == 0 && time <= 200) {
        out3 = "check";
    } else if (time > 200) {
        out3 = "Time out";
    } else {
        out3 = "Run Forest Run!";
    }

    std::cout << out3 << std::endl;

    return 0;
}