#include "Neuron.h"

Neuron::Neuron(double val)
{
	this->value = val;
	activate();
	derive();
}

void Neuron::activate()
{
	activatedValue = value / (1 + abs(value));
}
 
void Neuron::derive()
{
	derivedValue = activatedValue * (1 - activatedValue);
}
