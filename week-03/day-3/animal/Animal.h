//
// Created by Zoli on 2019. 04. 17..
//

#ifndef ANIMAL__ANIMAL_H_
#define ANIMAL__ANIMAL_H_

class Animal {
 public:
    Animal(int hunger, int thirst);
    Animal();
    int GetHunger() const;
    int GetThirst() const;
    void SetHunger(int hunger);
    void SetThirst(int thirst);
    void eat(int eat = 1);
    void drink(int drink = 1);
    void play(int play = 1);
 private:
    int _hunger;
    int _thirst;
};

#endif //ANIMAL__ANIMAL_H_
