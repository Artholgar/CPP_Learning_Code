#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<unsigned int> count_lower(const string& chaine)
{
    vector<unsigned int> dict(26, 0);

    for (auto c : chaine)
    {
        if (islower(c))
        {
            dict.at(c - 'a') += 1;
        }
    }

    return dict;
}

void display_lower_occ(const vector<unsigned int>& dict)
{
    for (long unsigned int i = 0; i < dict.size(); i++)
    {
        cout << (char)(i + 97) << " : " << dict.at(i) << endl;
    }
}

int main()
{
    string chaine;

    string temp_chaine;
    while (temp_chaine != "QUIT")
    {
        temp_chaine = "";
        cin >> temp_chaine;

        chaine += temp_chaine;
    }

    auto dict = count_lower(chaine);

    display_lower_occ(dict);

    return 0;
}