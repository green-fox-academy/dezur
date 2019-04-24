//
// Created by Zoli on 2019. 04. 24..
//

#include "StringedInstrument.h"

void StringedInstrument::setStrings(int strings)
{
    _strings = strings;
}

void StringedInstrument::setSounds(const std::string &sounds)
{
    _sounds = sounds;
}

const std::string &StringedInstrument::getSounds() const
{
    return _sounds;
}

int StringedInstrument::getStrings() const
{
    return _strings;
}
