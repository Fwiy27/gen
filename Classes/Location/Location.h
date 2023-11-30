#pragma once

#include <iostream>
#include <vector>
#include <map>
#include "../Chooser/Chooser.h"
#include "../FileParser/FileParser.h"

using namespace std;

class Location
{
    FileParser f;
    vector<string> cities;
    Chooser cityChooser;

public:
    Location();
    Location(int seed);
    string city();
    map<string, string> location();
};