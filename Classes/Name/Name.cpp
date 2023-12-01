#include "Name.h"

Name::Name()
{
    males = f.parseFile("Classes/Name/Names/males.txt");
    maleChooser = Chooser(males);

    females = f.parseFile("Classes/Name/Names/females.txt");
    femaleChooser = Chooser(females);

    middles = f.parseFile("Classes/Name/Names/mname.txt");
    middleNameChooser = Chooser(middles);

    lasts = f.parseFile("Classes/Name/Names/lname.txt");
    lastNameChooser = Chooser(lasts);
}

Name::Name(int seed)
{
    males = f.parseFile("Classes/Name/Names/males.txt");
    maleChooser = Chooser(males, seed);

    females = f.parseFile("Classes/Name/Names/females.txt");
    femaleChooser = Chooser(females, seed);

    middles = f.parseFile("Classes/Name/Names/mname.txt");
    middleNameChooser = Chooser(middles, seed);

    lasts = f.parseFile("Classes/Name/Names/lname.txt");
    lastNameChooser = Chooser(lasts, seed);
}

string Name::first(string gender)
{
    if (gender == "Male")
    {
        return maleChooser.choose();
    }
    else if (gender == "Female")
    {
        return femaleChooser.choose();
    }
    return "Jerry";
}

string Name::middle()
{
    return middleNameChooser.choose();
}

string Name::last()
{
    return lastNameChooser.choose();
}