#pragma once

#include <math.h>

class Neuron;

/// <summary>
/// Base class for activators used in neurons to calculate activated and derived values.
///	Other activator classes should derive this and override its methods.
/// </summary>
class Activator
{
public:

	Activator(Neuron* ownerNeuron)
		: owner(ownerNeuron){}
	virtual ~Activator() = default;

	// Virtual Methods
	virtual double getActivatedValue() = 0;
	virtual double getDerivedValue() = 0;

protected:
	Neuron* owner;
};




