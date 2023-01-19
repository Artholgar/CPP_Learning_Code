#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> braces { 4, 0 };

    vector<int> parenthesis(4, 0);

    int array[] = { 0, 1, 2, 3, 4, 5 };

    vector<int> part(&array[2], &array[5]);

    vector<int> full(array, array + 6);

    for (size_t left = 0, right = full.size() - 1; left < right; left++, right--)
    {
        swap(full[left], full[right]);
    }

    for (auto it = full.begin(); it != full.end(); it += 2)
    {
        it = full.emplace(it, *it);
    }

    while (!full.empty())
    {
        full.pop_back();
    }

    vector<int> v { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    v.erase(v.begin() + 2, v.begin() + 7);

    auto it = find(v.begin(), v.end(), 9);

    if (it != v.end())
    {
        v.erase(it);
    }

    v.assign(5, 2);
    v.assign({ 0, 2, 32, -4, 3 });
    v.clear();

    return 0;
}