#include "Random.h"

// Default Constructor
Random::Random()
{
    random_device rd;
    gen = mt19937(rd());
    numDist = uniform_int_distribution<int>(1, 10);
    normal = false;
    boolDist = uniform_int_distribution<int>(0, 1);
}

Random::Random(int seed)
{
    gen = mt19937(seed);
    numDist = uniform_int_distribution<int>(1, 10);
    normal = false;
    boolDist = uniform_int_distribution<int>(0, 1);
}

// Constructor for integer using random seed
Random::Random(int min, int max)
{
    random_device rd;
    gen = mt19937(rd());
    numDist = uniform_int_distribution<int>(min, max);
    normal = false;
    boolDist = uniform_int_distribution<int>(0, 1);
}
// Constructor for integer using seed
Random::Random(int min, int max, int seed)
{
    gen = mt19937(seed);
    numDist = uniform_int_distribution<int>(min, max);
    normal = false;
    boolDist = uniform_int_distribution<int>(0, 1);
}

// Constructor for integer using generator
Random::Random(int min, int max, mt19937 &gen)
{
    this->gen = gen;
    numDist = uniform_int_distribution<int>(min, max);
    normal = false;
    boolDist = uniform_int_distribution<int>(0, 1);
}

// Constructor for gaussian using random seed
Random::Random(double mean, double sd)
{
    random_device rd;
    gen = mt19937(rd());
    gauDist = normal_distribution<double>(mean, sd);
    normal = true;
    boolDist = uniform_int_distribution<int>(0, 1);
}

// Constructor for gaussian using seed
Random::Random(double mean, double sd, int seed)
{
    gen = mt19937(seed);
    gauDist = normal_distribution<double>(mean, sd);
    normal = true;
    boolDist = uniform_int_distribution<int>(0, 1);
}

// Constructor for gaussian using generator
Random::Random(double mean, double sd, mt19937 &gen)
{
    this->gen = gen;
    gauDist = normal_distribution<double>(mean, sd);
    normal = true;
    boolDist = uniform_int_distribution<int>(0, 1);
}

// Function to return a random integer
int Random::number()
{
    return (!normal) ? numDist(gen) : gauDist(gen);
}

// Function to return a random decimal
double Random::decimal()
{
    return gauDist(gen);
}

// Function to return random bool
bool Random::boolean()
{
    return boolDist(gen);
}
