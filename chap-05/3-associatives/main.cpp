#include "keys.h"

#include <iostream>
#include <map>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
    /*     set<ComparableDog> dogs;

        ComparableDog medor { "medor", "labrador" };
        dogs.emplace(medor);

        ComparableDog fox { "fox", "dobermann" };
        dogs.emplace(fox);

        ComparableDog medor_clone = medor;
        dogs.emplace(medor_clone);

        cout << dogs.size() << endl; */

    /* unordered_set<HashableDog> dogs;

    HashableDog medor { "medor", "Labrador" };
    dogs.emplace(medor);

    HashableDog fox { "fox", "dobermann" };
    dogs.emplace(fox);

    HashableDog medor_clone = medor;
    dogs.emplace(medor_clone);

    cout << dogs.size() << endl; */

    using Owner = std::pair<std::string, std::string>;
    map<ComparableDog, Owner> owner_by_dogs;

    ComparableDog medor { "medor", "labrador" };
    ComparableDog gus { "gus", "bordercollie" };
    ComparableDog zim { "zim", "poodle" };
    ComparableDog flippy { "flippy", "spaniel" };

    owner_by_dogs.insert({ medor, Owner { "David", "Hing" } });
    owner_by_dogs.insert_or_assign(gus, Owner { "Leila", "Wallner" });
    owner_by_dogs.emplace(zim, Owner { "Thomas", "Josephine" });
    owner_by_dogs.try_emplace(flippy, "Samy", "Attal");

    return 0;
}