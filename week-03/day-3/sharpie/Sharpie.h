//
// Created by Zoli on 2019. 04. 17..
//

#ifndef SHARPIE__SHARPIE_H_
#define SHARPIE__SHARPIE_H_

#include <iostream>

class Sharpie {
 public:
    Sharpie(const std::string &color, float width, float ink_amount);
    Sharpie(const std::string &color, float width);
    const std::string &GetColor() const;
    float GetWidth() const;
    float GetInkAmount() const;
    void SetColor(const std::string &color);
    void SetWidth(float width);
    void SetInkAmount(float ink_amount);
    void use();
 private:
    std::string _color;
    float _width;
    float _inkAmount;
};

#endif //SHARPIE__SHARPIE_H_
