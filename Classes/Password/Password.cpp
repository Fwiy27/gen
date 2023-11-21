#include "Password.h"

Password::Password()
{
    decider = Random(1, 4);
    lowerLetterRand = Random(97, 122);
    upperLetterRand = Random(65, 90);
    symbolChooser = Chooser(symbols);
    numberRand = Random(48, 57);
}

Password::Password(int seed)
{
    decider = Random(1, 4, seed);
    lowerLetterRand = Random(97, 122, seed);
    upperLetterRand = Random(65, 90, seed);
    symbolChooser = Chooser(symbols, seed);
    numberRand = Random(48, 57, seed);
}

char Password::letter(bool lower)
{
    return ((lower) ? lowerLetterRand.number() : upperLetterRand.number());
}

char Password::number()
{
    return numberRand.number();
}

char Password::symbol()
{
    return symbolChooser.cc();
}

string Password::generate(int length)
{
    string pass;
    pass += letter((decider.number() <= 2) ? true : false);

    for (int i = 0; i < length - 4; i++)
    {
        switch (decider.number())
        {
        case 1:
            pass += letter(true);
            break;
        case 2:
            pass += letter(false);
            break;
        case 3:
            pass += number();
            break;
        case 4:
            pass += symbol();
            break;
        }
    }

    switch (decider.number())
    {
    case 1:
        pass += symbol();
        pass += number();
        pass += number();
        break;
    case 2:
        pass += number();
        pass += symbol();
        pass += number();
        break;
    case 3 ... 4:
        pass += number();
        pass += number();
        pass += symbol();
        break;
    }

    return pass;
}