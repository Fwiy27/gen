#include <iostream>
#include <map>
#include "../Random/Random.h"

using namespace std;

class Date
{
    int seed;
    Random monthRand;
    Random dayRand;
    Random yearRand;
    string day30 = "4,6,9,11";
    string day31 = "1,3,5,7,8,10,12";
    map<int, string> monthMap = {{1, "January"}, {2, "February"}, {3, "March"}, {4, "April"}, {5, "May"}, {6, "June"}, {7, "July"}, {8, "August"}, {9, "September"}, {10, "October"}, {11, "November"}, {12, "December"}};

public:
    Date();
    Date(int yearMin, int yearMax);
    Date(int yearMin, int yearMax, int seed);
    int month();
    int day(int month);
    int year();
    string date();
    map<string, string> ddate();
};