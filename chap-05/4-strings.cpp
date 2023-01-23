#include <iostream>
#include <string>

void print_in_console(std::string_view str)
{
    std::cout << str << std::endl;
}

int main()
{
    print_in_console("print me");
    return 0;
}
