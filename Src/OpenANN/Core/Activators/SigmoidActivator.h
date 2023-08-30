#pragma once
#include "Activator.h"


class SigmoidActivator : public Activator
{
public:
	explicit SigmoidActivator(Neuron* ownerNeuron)
		: Activator(ownerNeuron)
	{
	}

	double getActivatedValue() override;
	double getDerivedValue() override;
};

