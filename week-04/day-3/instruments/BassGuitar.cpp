//
// Created by Zoli on 2019. 04. 24..
//

#include "BassGuitar.h"

BassGuitar::BassGuitar() {
    setStrings(4);
    setSounds("Duum-duum-dumm");
}

BassGuitar::BassGuitar(int numOfStrings) {
    setStrings(numOfStrings);
    setSounds("Duum-duum-dumm");
}

std::string BassGuitar::sound() {
    return getSounds();
}

void BassGuitar::play() {
    std::cout << "Bass guitar, a " << getStrings() << "-stringed instrument that goes " << sound() << std::endl;
}

