#pragma once

#include <iostream>

class Dog : public Animal
{
public:
    void sing() const { std::cout << "Waf" << std::endl; }
};
