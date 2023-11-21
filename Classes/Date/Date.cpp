#include "Date.h"

Date::Date(int yearMin, int yearMax)
{
    monthRand = Random(1, 12);
    yearRand = Random(yearMin, yearMax);
}

Date::Date(int yearMin, int yearMax, int seed)
{
    this->seed = seed;
    monthRand = Random(1, 12, seed);
    yearRand = Random(yearMin, yearMax, seed);
}

int Date::month() { return monthRand.number(); }

int Date::year() { return yearRand.number(); }

int Date::day(int month)
{
    string m = to_string(month);
    if (day31.find(m) != -1)
    {
        if (seed > 0)
        {
            dayRand = Random(1, 31, seed);
        }
        else
        {
            dayRand = Random(1, 31);
        }
    }
    else if (day30.find(m) != -1)
    {
        if (seed > 0)
        {
            dayRand = Random(1, 30, seed);
        }
        else
        {
            dayRand = Random(1, 30);
        }
    }
    else
    {
        if (seed > 0)
        {
            dayRand = Random(1, 28, seed);
        }
        else
        {
            dayRand = Random(1, 28);
        }
    }
    return dayRand.number();
}

string Date::date()
{
    int m = month();
    int d = day(m);
    int y = year();
    return (to_string(m) + "/" + to_string(d) + "/" + to_string(y));
}

map<string, string> Date::ddate()
{
    map<string, string> mp;
    int m = month();
    int d = day(m);
    int y = year();
    mp["Date"] = (to_string(m) + "/" + to_string(d) + "/" + to_string(y));
    mp["Month"] = monthMap[m];
    mp["Day"] = to_string(d);
    mp["Year"] = to_string(y);
    return mp;
}