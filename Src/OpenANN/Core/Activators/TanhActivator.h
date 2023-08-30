#pragma once
#include "Activator.h"


class TanhActivator : public Activator
{
public:
	explicit TanhActivator(Neuron* ownerNeuron)
		: Activator(ownerNeuron)
	{
	}

	double getActivatedValue() override;
	double getDerivedValue() override;
};

