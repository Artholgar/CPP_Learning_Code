#pragma once

#include <string>

class ComparableDog
{
public:
    ComparableDog(const std::string& name, const std::string& species)
        : _name { name }
        , _species { species }
    {}

    bool operator<(const ComparableDog& other) const
    {
        if (_name < other._name)
        {
            return true;
        }
        else if (other._name < _name)
        {
            return false;
        }
        else
        {
            return _species < other._species;
        }
    }

private:
    std::string _name;
    std::string _species;
};

class HashableDog
{
public:
    HashableDog(const std::string& name, const std::string& species)
        : _name { name }
        , _species { species }
    {}

    bool operator==(const HashableDog& other) const
    {
        return _name == other._name && _species == other._species;
    }

    size_t get_hash() const
    {
        std::hash<std::string> hash_fct;
        return hash_fct(_name) + hash_fct(_species);
    }

private:
    std::string _name;
    std::string _species;
};

namespace std {

template <>
struct hash<HashableDog>
{
    size_t operator()(const HashableDog& c) const { return c.get_hash(); }
};

} // namespace std
