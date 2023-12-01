#pragma once

#include <iostream>
#include <random>

using namespace std;

class Random
{
    // boolean for if the distribution is a bell curve
    bool normal;
    // random number generator
    mt19937 gen;
    // distribution for random number
    uniform_int_distribution<int> numDist;
    // distribution for random gaussian
    normal_distribution<double> gauDist;
    // distribution for random bool
    uniform_int_distribution<int> boolDist;

public:
    // Default Constructor
    Random();
    // Constructor with seed
    Random(int seed);
    // Constructor for integer using random seed
    Random(int min, int max);
    // Constructor for integer using seed
    Random(int min, int max, int seed);
    // Constructor for integer using generator
    Random(int min, int max, mt19937 &gen);
    // Constructor for gaussian using random seed
    Random(double mean, double sd);
    // Constructor for gaussian using seed
    Random(double mean, double sd, int seed);
    // Constructor for gaussian using gen
    Random(double mean, double sd, mt19937 &gen);
    // Function to return random number
    int number();
    // Function to return random double
    double decimal();
    // Function to return random bool
    bool boolean();
};