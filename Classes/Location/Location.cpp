#include "Location.h"

Location::Location()
{
    cities = f.parseFile("Classes/Location/Cities/Cities.txt");
    cityChooser = Chooser(cities);
}

Location::Location(int seed)
{
    cities = f.parseFile("Classes/Location/Cities/Cities.txt");
    cityChooser = Chooser(cities, seed);
}

string Location::city()
{
    string city = cityChooser.choose();
    return city.substr(0, city.find(","));
}

map<string, string> Location::location()
{
    map<string, string> loc;
    string fullLocation = cityChooser.choose();
    loc["City"] = fullLocation.substr(0, fullLocation.find(","));
    loc["State"] = fullLocation.substr(fullLocation.find(",") + 1).substr(3);
    loc["State Short"] = fullLocation.substr(fullLocation.find(",") + 1, 2);
    return loc;
}