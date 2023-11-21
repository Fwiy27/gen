#include <iostream>
#include "../Random/Random.h"

using namespace std;

class Email
{
    Random numbers;

public:
    Email();
    Email(int seed);
    string email(string firstName, string middleName, string lastName);
};