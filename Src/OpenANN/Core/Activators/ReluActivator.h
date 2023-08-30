#pragma once
#include "Activator.h"

class ReluActivator : public Activator
{
public:
	explicit ReluActivator(Neuron* ownerNeuron)
		: Activator(ownerNeuron)
	{
	}

	double getActivatedValue() override;
	double getDerivedValue() override;
};

