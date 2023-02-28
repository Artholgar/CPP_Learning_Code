#pragma once

#include <iostream>

class Chicken : public Animal
{
public:
    void sing() const { std::cout << "Cotcotcotcodet" << std::endl; }
};
