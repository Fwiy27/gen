#pragma once

#include <iostream>
#include "../Random/Random.h"

using namespace std;

class Email
{
    Random numbersRand;

public:
    Email();
    Email(int seed);
    string email(string first, string middle, string last);
};