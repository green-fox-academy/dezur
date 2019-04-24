//
// Created by Zoli on 2019. 04. 24..
//

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H


#include "StringedInstrument.h"

class BassGuitar : public StringedInstrument {
public:
    BassGuitar();
    BassGuitar(int);
    std::string sound();
    void play();

};


#endif //INSTRUMENTS_BASSGUITAR_H
