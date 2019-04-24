//
// Created by Zoli on 2019. 04. 24..
//

#ifndef INSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTS_INSTRUMENT_H


#include <string>

class Instrument {
public:
    virtual void play() = 0;
protected:
    std::string name;
};


#endif //INSTRUMENTS_INSTRUMENT_H
