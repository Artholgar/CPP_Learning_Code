#include "Employee.h"

Employee::Employee(std::string_view name, std::string_view surname, unsigned int salary, Rank rank)
    : _name { name }
    , _surname { surname }
    , _salary { salary }
    , _rank { rank }
{}

void Employee::increase_salary(unsigned int raise)
{
    _salary += raise;
}