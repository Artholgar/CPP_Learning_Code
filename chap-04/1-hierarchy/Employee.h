#pragma once

#include "Rank.h"

#include <string>
#include <string_view>

class Employee
{
public:
    Employee(std::string_view name, std::string_view surname, unsigned int salary, Rank rank);

    const std::string& get_name() const { return _name; }
    const std::string& get_surname() const { return _surname; }

    unsigned int get_salary() const { return _salary; }

    void increase_salary(unsigned int raise);

    Rank get_rank() const { return _rank; }

private:
    const std::string _name;
    const std::string _surname;
    unsigned int      _salary;
    Rank              _rank;
};