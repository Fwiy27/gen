#include "Email.h"

Email::Email()
{
    numbers = Random(100, 999);
}

Email::Email(int seed)
{
    numbers = Random(100, 999, seed);
}

string Email::email(string firstName, string middleName, string lastName)
{
    return (firstName + middleName.substr(0, 1) + lastName.substr(0, 1) + to_string(numbers.number()) + "@gmail.com");
}