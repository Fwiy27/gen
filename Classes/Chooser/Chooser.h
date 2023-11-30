#pragma once

#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Chooser
{
    vector<string> items;
    vector<char> charItems;
    random_device *rd;
    mt19937 gen;
    uniform_int_distribution<int> dist;

public:
    Chooser();
    Chooser(vector<string> items);
    Chooser(vector<string> items, int seed);
    Chooser(vector<char> charItems);
    Chooser(vector<char> charItems, int seed);
    string choose();
    char chooseChar();
};