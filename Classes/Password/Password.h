#include <iostream>
#include <vector>
#include "../Chooser/Chooser.h"

using namespace std;

class Password
{
    Random decider;
    Random lowerLetterRand;
    Random upperLetterRand;
    Random numberRand;

    vector<char> symbols = {'!', '%', '_', '+', '-', ':', '?', '='};

    Chooser symbolChooser;

    char letter(bool lower);
    char number();
    char symbol();

public:
    Password();
    Password(int seed);
    string generate(int length);
};