#pragma once

#include <iostream>
#include <vector>
#include "../Random/Random.h"

using namespace std;

class Chooser
{
    Random r;
    vector<char> cv;
    vector<string> sv;
    vector<int> iv;
    vector<double> dv;

public:
    Chooser();
    Chooser(vector<char> v);
    Chooser(vector<char> v, int seed);
    Chooser(vector<string> v);
    Chooser(vector<string> v, int seed);
    Chooser(vector<int> v);
    Chooser(vector<int> v, int seed);
    Chooser(vector<double> v);
    Chooser(vector<double> v, int seed);

    char cc();
    string cs();
    int ci();
    double cd();
};