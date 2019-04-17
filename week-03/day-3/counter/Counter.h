//
// Created by Zoli on 2019. 04. 17..
//

#ifndef COUNTER__COUNTER_H_
#define COUNTER__COUNTER_H_

class Counter {
 public:
    Counter(int number);
    Counter();
    int value = 0;
    int get() const;
    void SetNumber(int number);
    void add(int value);
    void add();
    void reset();
 private:
    int _number;
};

#endif //COUNTER__COUNTER_H_
