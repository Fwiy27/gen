#pragma once

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileParser
{
    ifstream parser;

public:
    FileParser();
    vector<string> parseFile(string fileName);
};