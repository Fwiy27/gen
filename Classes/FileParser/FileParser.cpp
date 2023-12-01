#include "FileParser.h"

FileParser::FileParser() {}

vector<string> FileParser::parseFile(string fileName)
{
    vector<string> v;
    string line;
    parser.open(fileName);
    while (!parser.eof())
    {
        getline(parser, line);
        v.push_back(line);
    }
    parser.close();
    return v;
}