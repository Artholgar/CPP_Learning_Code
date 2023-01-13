#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

bool parse_params(int argc, char* argv[], string& dict_path, string& word, string& translation,
                  vector<string>& sentence);
vector<pair<string, string>> open_dictionary(const string& path);
void                         save_dictionary(const string& path, const vector<pair<string, string>>& dict);
void                         translate(vector<string>& sentence, const vector<pair<string, string>>& dict);

int main(int argc, char* argv[])
{
    string         dict_path, word, translation;
    vector<string> sentence;

    if (!parse_params(argc, argv, dict_path, word, translation, sentence))
    {
        return -1;
    }

    vector<pair<string, string>> dict;

    if (!dict_path.empty())
    {
        dict = open_dictionary(dict_path);
    }

    if (!word.empty() && !translation.empty())
    {
        dict.emplace_back(pair<string, string> { word, translation });

        if (!dict_path.empty())
        {
            save_dictionary(dict_path, dict);
        }
    }

    if (!sentence.empty())
    {
        translate(sentence, dict);
    }

    return 0;
}

bool parse_params(int argc, char* argv[], string& dict_path, string& word, string& translation,
                  vector<string>& sentence)
{
    for (auto i = 1; i < argc; ++i)
    {
        string option = argv[i];

        if (option == "-d" && (i + 1) < argc)
        {
            dict_path = argv[++i];
        }
        else if (option == "-a" && (i + 2) < argc)
        {
            word        = argv[++i];
            translation = argv[++i];
        }
        else
        {
            sentence.emplace_back(argv[i]);
        }
    }

    if (dict_path.empty())
    {
        cerr << "No dictionary path was provided." << endl;
        return false;
    }

    return true;
}

vector<pair<string, string>> open_dictionary(const string& path)
{
    vector<pair<string, string>> dict;

    fstream file { path, ios_base::in };

    if (!file.is_open())
    {
        cout << "failed to opend dictionary" << endl;
    }

    while (!file.eof())
    {
        string word;
        file >> word;

        string translation;
        file >> translation;

        if (word.empty() || translation.empty())
        {
            continue;
        }

        dict.emplace_back(pair<string, string> { word, translation });
    }

    return dict;
}

void save_dictionary(const string& path, const vector<pair<string, string>>& dict)
{
    fstream file { path, ios_base::out };

    if (!file.is_open())
    {
        cout << "failed to opend dictionary" << endl;
    }

    for (auto word_translation : dict)
    {
        file << word_translation.first << " " << word_translation.second << std::endl;
    }
}

void translate(vector<string>& sentence, const vector<pair<string, string>>& dict)
{
    for (auto word : sentence)
    {
        auto have_been_translated = false;
        for (auto word_translation : dict)
        {
            if (word == word_translation.first)
            {
                cout << word_translation.second << " ";
                have_been_translated = true;
            }
        }

        if (!have_been_translated)
        {
            cout << "???"
                 << " ";
        }
    }
    cout << endl;
}
