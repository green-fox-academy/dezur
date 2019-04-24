//
// Created by Zoli on 2019. 04. 24..
//

#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar() {
    setStrings(6);
    setSounds("Twang");
}

ElectricGuitar::ElectricGuitar(int numOfStrings){
    setStrings(numOfStrings);
    setSounds("Twang");
};

void ElectricGuitar::play() {
    std::cout << "Electric guitar, a " << getStrings() << "-stringed instrument that goes " << sound() << std::endl;
}

std::string ElectricGuitar::sound() {
    return getSounds();
}
