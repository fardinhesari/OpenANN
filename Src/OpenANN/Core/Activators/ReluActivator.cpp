#include "ReluActivator.h"
#include "../Neuron.h"

double ReluActivator::getActivatedValue()
{
	double val = owner->getValue();
	if (val >= 0)
	{
		return val;
	}
	return 0;
}

double ReluActivator::getDerivedValue()
{
	double val = owner->getValue();
	if (val >= 0)
	{
		return 1;
	}
	return 0;
}
