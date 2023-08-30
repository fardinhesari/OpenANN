#include "TanhActivator.h"
#include "../Neuron.h"

double TanhActivator::getActivatedValue()
{
	return std::tanh(owner->getValue());
}

double TanhActivator::getDerivedValue()
{
	return 1 - std::pow(owner->getActivatedValue(), 2);
}
