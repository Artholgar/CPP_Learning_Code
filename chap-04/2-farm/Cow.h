#pragma once

#include <iostream>

class Cow : public Animal
{
public:
    void sing() const { std::cout << "Mewwwwwh" << std::endl; }
};
