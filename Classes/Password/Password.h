#pragma once

#include <iostream>
#include <vector>
#include "../Random/Random.h"

using namespace std;

class Password
{
    Random decider;
    Random lowerLetterRand;
    Random upperLetterRand;
    Random numberRand;

    string symbols;

    Random symbolRand;

    char letter(bool lower);
    char number();
    char symbol();

public:
    Password();
    Password(int seed);
    string generate(int length);
};