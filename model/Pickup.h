#ifndef PICKUP_H
#define PICKUP_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <random>
#include <bits/stdc++.h>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
using std::map;

class Pickup{
    protected:
        string sprite;
        int value;
        pair<int, int> position;
    public:
        Pickup();
        ~Pickup();
        Pickup(string sprite, int value, pair<int, int> position);
        pair<int, int> getPosition();
}

#endif