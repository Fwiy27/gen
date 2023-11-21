#include "City.h"

City::City()
{
    pairRand = Random(0, 29864);
    statesRand = Random(0, 50);
}
City::City(int seed)
{
    pairRand = Random(0, 29864, seed);
    statesRand = Random(0, 50, seed);
}
string City::city()
{
    string full = pairs[pairRand.number()];
    return full.substr(0, full.find(","));
}
string City::state()
{
    return states[statesRand.number()];
}
map<string, string> City::pair()
{
    map<string, string> m;
    string full = pairs[pairRand.number()];
    string stateFull = full.substr(full.find(",") + 1);
    m["City"] = full.substr(0, full.find(","));
    m["State Short"] = stateFull.substr(0, 2);
    m["State Long"] = stateFull.substr(3);
    return m;
}