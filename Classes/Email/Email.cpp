#include "Email.h"

Email::Email()
{
    numbersRand = Random(100, 999);
}

Email::Email(int seed)
{
    numbersRand = Random(100, 999, seed);
}

string Email::email(string first, string middle, string last)
{
    return (first + middle.substr(0, 1) + last.substr(0, 1) + to_string(numbersRand.number()) + "@gmail.com");
}