#include "Layer.h"

Layer::Layer(int size)
{
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		Neuron* n = new Neuron(0.0);
		neurons.push_back(n);
	}
}
