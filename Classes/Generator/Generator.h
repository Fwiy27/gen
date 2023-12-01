#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>

#include "../Random/Random.h"
#include "../Chooser/Chooser.h"
#include "../Name/Name.h"
#include "../Date/Date.h"
#include "../Location/Location.h"
#include "../Email/Email.h"
#include "../Password/Password.h"

using namespace std;

class Generator
{
    void clearScreen();

    Chooser genderRand;
    int seed;

    Name n;
    Date d;
    Location l;
    Email e;
    Password p;

    void generator();
    void details();
    int seedInput();
    string genderInput();
    void init(int seed);

public:
    Generator();
    map<string, string> generate(string gender);
    string to_string(map<string, string> person);
    void ui();
};