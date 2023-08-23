#pragma once
#include <vector>

#include "Neuron.h"

using namespace std;

class Layer
{
public:
	Layer(int size);

private:
	int size;
	vector<Neuron*> neurons;

};

