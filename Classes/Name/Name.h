#pragma once

#include <iostream>
#include <vector>
#include "../Chooser/Chooser.h"
#include "../FileParser/FileParser.h"

using namespace std;

class Name
{
    FileParser f;

    vector<string> males;
    vector<string> females;
    vector<string> middles;
    vector<string> lasts;

    Chooser maleChooser;
    Chooser femaleChooser;
    Chooser middleNameChooser;
    Chooser lastNameChooser;

public:
    Name();
    Name(int seed);
    string first(string gender);
    string middle();
    string last();
};