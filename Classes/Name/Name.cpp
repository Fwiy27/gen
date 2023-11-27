#include "Name.h"

Name::Name()
{
    firstMaleRand = Random(0, 1218);
    firstFemaleRand = Random(0, 4275);
    middleRand = Random(0, 3897);
    lastRand = Random(0, 88800);
}

Name::Name(int seed)
{
    firstMaleRand = Random(0, 1218, seed);
    firstFemaleRand = Random(0, 4275, seed);
    middleRand = Random(0, 3897, seed);
    lastRand = Random(0, 88800, seed);
}

string Name::first(string gender)
{
    if (gender == "Male")
    {
        return firstMales[firstMaleRand.number()];
    }
    else if (gender == "Female")
    {
        return firstFemales[firstFemaleRand.number()];
    }
    return "Invalid";
}

string Name::middle() { return middleNames[middleRand.number()]; }

string Name::last() { return lastNames[lastRand.number()]; }