#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include "../City/City.h"
#include "../Email/Email.h"
#include "../Date/Date.h"
#include "../Name/Name.h"
#include "../Password/Password.h"
#include "../Chooser/Chooser.h"

using namespace std;

class Generator
{
    int choice;
    City c;
    Date d;
    Email e;
    Name n;
    Password p;
    Chooser ch;

    void clear_screen();
    void print_logo();

public:
    Generator();
    Generator(int seed);
    void ui();
    map<string, string> generate(string gender);
    void printPerson(map<string, string> person);
};