//
// Created by Zoli on 2019. 04. 24..
//

#include "Violin.h"

Violin::Violin() {
    setStrings(4);
    setSounds("Screech");
    _name = "Violin";
}

Violin::Violin(int numOfStrings) {
    setStrings(numOfStrings);
    setSounds("Screech");
    _name = "Violin";
}

void Violin::play() {
    std::cout << _name << ", a " << getStrings() << "-stringed instrument that goes " << sound() << std::endl;
}

std::string Violin::sound() {
    return getSounds();
}
