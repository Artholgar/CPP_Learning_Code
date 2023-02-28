#pragma once

#include <iostream>

class Cat : public Animal
{
public:
    void sing() const { std::cout << "Meow" << std::endl; }
};
