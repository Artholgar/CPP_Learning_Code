/* #include <iostream>

struct Test
{
    Test(int v)
        : value { v }
    {
        std::cout << "Constructor was called with " << v << "." << std::endl;
    }

    Test(const Test& other)
        : value { other.value }
    {
        std::cout << "Copy constructor was called." << std::endl;
    }

    int value = 0;
};

Test create_test(int value)
{
    Test result { value };
    return result;
}

int main()
{
    Test test = create_test(3);
    std::cout << test.value << std::endl;

    return 0;
} */

/* #include <iostream>
#include <memory>
#include <utility>
#include <vector>

int main()
{
    std::vector<std::unique_ptr<std::string>> many_strings;

    auto value = std::make_unique<std::string>("text");

    if (value != nullptr)
    {
        std::cout << "value is " << *value << std::endl;
    }
    else
    {
        std::cout << "value is empty" << std::endl;
    }

    many_strings.emplace_back(std::move(value));

    if (value != nullptr)
    {
        std::cout << "value is " << *value << std::endl;
    }
    else
    {
        std::cout << "value is empty" << std::endl;
    }

    if (many_strings[0] != nullptr)
    {
        std::cout << "many_ints[0] is " << *many_strings[0] << std::endl;
    }
    else
    {
        std::cout << "many_ints[0] is empty" << std::endl;
    }

    return 0;
} */

#include <iostream>
#include <memory>
#include <utility>

void display(const std::string& variable_name, const std::unique_ptr<int>& variable)
{
    if (variable)
    {
        std::cout << variable_name << " contains " << *variable << std::endl;
    }
    else
    {
        std::cout << variable_name << " is empty" << std::endl;
    }
}

std::unique_ptr<int> passthrough(std::unique_ptr<int> ptr)
{
    std::unique_ptr<int> local = std::move(ptr);

    return local;
}

int main()
{
    auto i1 = std::make_unique<int>(3);
    auto i2 = std::make_unique<int>(8);

    std::cout << "Before passthrough call" << std::endl;
    display("i1", i1);
    display("i2", i2);
    std::cout << "--------------------------" << std::endl;

    i2 = passthrough(std::move(i1));

    std::cout << "After passthrough call" << std::endl;
    display("i1", i1);
    display("i2", i2);
    std::cout << "--------------------------" << std::endl;

    return 0;
}