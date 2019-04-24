//
// Created by Zoli on 2019. 04. 24..
//

#include "Violin.h"

Violin::Violin() {
    setStrings(4);
    setSounds("Screech");
}

Violin::Violin(int numOfStrings) {
    setStrings(numOfStrings);
    setSounds("Screech");
}

void Violin::play() {
    std::cout << "Violin, a " << getStrings() << "-stringed instrument that goes " << sound() << std::endl;
}

std::string Violin::sound() {
    return getSounds();
}
