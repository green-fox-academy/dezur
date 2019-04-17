//
// Created by Zoli on 2019. 04. 17..
//

#include "Animal.h"
Animal::Animal(int hunger, int thirst) : _hunger(hunger), _thirst(thirst)
{}

Animal::Animal()
{
    Animal::_hunger = 50;
    Animal::_thirst = 50;
}

int Animal::GetHunger() const
{
    return _hunger;
}
int Animal::GetThirst() const
{
    return _thirst;
}
void Animal::SetHunger(int hunger)
{
    _hunger = hunger;
}
void Animal::SetThirst(int thirst)
{
    _thirst = thirst;
}

void Animal::eat(int eat)
{
    _hunger -= 1;
}

void Animal::drink(int drink)
{
    _thirst -= 1;
}

void Animal::play(int play)
{
    _hunger += 1;
    _thirst += 1;
}
