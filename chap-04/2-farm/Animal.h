#pragma once

#include <iostream>

class Animal
{
public:
    virtual void sing() const { std::cout << "..." << std::endl; }
};
