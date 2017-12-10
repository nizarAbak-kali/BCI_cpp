//
// Created by Nizar on 10/12/2017.
//

#ifndef BCI2_CONNECTION_H
#define BCI2_CONNECTION_H
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

struct Connection
{
    double weight;
    double deltaWeight;
};

class Neuron;

typedef vector<Neuron> Layer;

#endif //BCI2_CONNECTION_H
