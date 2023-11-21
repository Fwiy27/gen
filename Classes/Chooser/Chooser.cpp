#include "Chooser.h"

Chooser::Chooser()
{
}

Chooser::Chooser(vector<char> v)
{
    cv = v;
    r = Random(0, v.size() - 1);
}

Chooser::Chooser(vector<char> v, int seed)
{
    cv = v;
    r = Random(0, v.size() - 1, seed);
}

Chooser::Chooser(vector<string> v)
{
    sv = v;
    r = Random(0, v.size() - 1);
}

Chooser::Chooser(vector<string> v, int seed)
{
    sv = v;
    r = Random(0, v.size() - 1, seed);
}

Chooser::Chooser(vector<int> v)
{
    iv = v;
    r = Random(0, v.size() - 1);
}

Chooser::Chooser(vector<int> v, int seed)
{
    iv = v;
    r = Random(0, v.size() - 1, seed);
}

Chooser::Chooser(vector<double> v)
{
    dv = v;
    r = Random(0, v.size() - 1);
}

Chooser::Chooser(vector<double> v, int seed)
{
    dv = v;
    r = Random(0, v.size() - 1, seed);
}

char Chooser::cc()
{
    return cv[r.number()];
}

string Chooser::cs()
{
    return sv[r.number()];
}

int Chooser::ci()
{
    return iv[r.number()];
}

double Chooser::cd()
{
    return dv[r.number()];
}