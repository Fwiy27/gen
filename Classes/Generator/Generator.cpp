#include "Generator.h"

Generator::Generator()
{
}

Generator::Generator(int seed)
{
}

void Generator::clear_screen()
{
    cout << "\033[2J\033[1;1H";
}