#include <iostream>
#include <string>
#include <tuple>

std::tuple<bool, int, int> parse_params(int argc, const char* const* argv)
{
    const std::tuple<bool, int, int> error { false, 0, 0 };

    if (argc != 3)
    {
        std::cerr << "Program expects 2 parameters!" << std::endl;
        return error;
    }

    std::string num_str = argv[1];
    std::string den_str = argv[2];

    int num = 0;
    int den = 0;
    try
    {
        num = std::stoi(num_str);
        den = std::stoi(den_str);
    }
    catch (const std::exception&)
    {
        std::cerr << "Program expects 2 integer parameters!" << std::endl;
        return error;
    }

    if (den == 0)
    {
        std::cerr << "Denominator cannot be null!" << std::endl;
        return error;
    }

    return std::tuple { true, num, den };
}

std::tuple<int, int> divide(int numerator, int denominator)
{
    return std::tuple<int, int> { numerator / denominator, numerator % denominator };
}

int main(int argc, char** argv)
{
    const auto pars_res = parse_params(argc, argv);

    if (!std::get<0>(pars_res))
    {
        return 1;
    }

    const auto numerator   = std::get<1>(pars_res);
    const auto denominator = std::get<2>(pars_res);
    const auto div_res     = divide(numerator, denominator);
    const auto quotient    = std::get<0>(div_res);
    const auto reminder    = std::get<1>(div_res);

    std::cout << numerator << " = " << denominator << " * " << quotient << " + " << reminder << std::endl;

    return 0;
}