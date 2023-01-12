#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error : program must take 1 argument" << std::endl;
        return -1;
    }

    std::cout << argv[1] << std::endl;

    int array_size = std::stoi(argv[1]);

    std::vector<int> array;

    for (int i = 0; i < array_size; ++i)
    {
        array.emplace_back(i + 1);
    }

    for (int value : array)
    {
        std::cout << value << std::endl;
    }
    /*
    int array[array_size] = {};

    for (int i = 0; i < array_size; i++)
    {
        array[i] = i + 1;
    }

    for (int value : array)
    {
        std::cout << value << std::endl;
    }
    */

    return 0;
}
