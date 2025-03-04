#include "Cat.h"

#include <iostream>
#include <memory>

int main()
{
    auto cat1 = std::make_unique<Cat>("Felix");

    std::cout << *cat1 << std::endl;

    std::unique_ptr<Cat> cat2;

    if (cat2 == nullptr)
    {
        std::cout << "Cat 2 is nullptr" << std::endl;
    }

    cat2 = std::make_unique<Cat>("Uscka");

    std::cout << "cat1 == cat2 ? " << (cat1 == cat2) << std::endl;
    std::cout << "*cat1 == *cat2 ? " << (*cat1 == *cat2) << std::endl;

    cat1.reset();
    if (cat1 == nullptr)
    {
        std::cout << "cat1 is nullptr." << std::endl;
    }

    return 0;
}