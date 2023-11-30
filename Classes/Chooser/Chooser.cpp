#include "Chooser.h"

Chooser::Chooser()
{
    rd = new random_device;
    items.assign({"1", "2", "3"});
    gen = mt19937((*rd)());
    dist = uniform_int_distribution<int>(0, 2);
}

Chooser::Chooser(vector<string> items)
{
    rd = new random_device;
    this->items = items;
    gen = mt19937((*rd)());
    dist = uniform_int_distribution<int>(0, items.size() - 1);
}

Chooser::Chooser(vector<string> items, int seed)
{
    this->items = items;
    gen = mt19937(seed);
    dist = uniform_int_distribution<int>(0, items.size() - 1);
}

Chooser::Chooser(vector<char> charItems)
{
    rd = new random_device;
    this->charItems = charItems;
    gen = mt19937((*rd)());
    dist = uniform_int_distribution<int>(0, charItems.size() - 1);
}

Chooser::Chooser(vector<char> charItems, int seed)
{
    this->charItems = charItems;
    gen = mt19937(seed);
    dist = uniform_int_distribution<int>(0, charItems.size() - 1);
}

string Chooser::choose()
{
    return items[dist(gen)];
}

char Chooser::chooseChar()
{
    return charItems[dist(gen)];
}