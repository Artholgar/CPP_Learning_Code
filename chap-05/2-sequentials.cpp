#include <array>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

using namespace std;

enum Fruit
{
    Apricot,
    Cherry,
    Mango,
    Raspberry,

    Fruit_Count,
};

void try_arrays()
{
    array<string, Fruit_Count> fruit_names;
    fruit_names[Apricot]   = "Apricot";
    fruit_names[Cherry]    = "Cherry";
    fruit_names[Mango]     = "Mango";
    fruit_names[Raspberry] = "Raspberry";
}

void try_lists()
{
    std::list<int> l1 { -2, -3, 7, 200, -8, 6 };
    std::list<int> l2(3, -45);

    std::list<int> l3;
    l3.assign({ 41, 6, 12 });

    std::list<int> l4;
    l4.emplace_front(0);
    l4.emplace_front(4);
    l4.emplace_front(6);

    l1.sort();
    l2.sort();
    l1.merge(l2);

    l3.splice(l3.begin(), l4);
    l3.sort();

    auto mid = l1.begin();
    advance(mid, l1.size() / 2);
    l1.splice(mid, l3);
}

void try_stacks()
{
    std::stack<int, std::vector<int>> s1;
    s1.emplace(0);
    s1.emplace(1);
    s1.emplace(2);
}

int main()
{
    try_arrays();
    try_lists();
    try_stacks();

    return 0;
}