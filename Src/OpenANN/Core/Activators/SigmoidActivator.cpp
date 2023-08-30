#include "SigmoidActivator.h"
#include "../Neuron.h"


double SigmoidActivator::getActivatedValue()
{
	return 1 / (1 + std::exp(-owner->getValue()));
}

double SigmoidActivator::getDerivedValue()
{
	double av = owner->getActivatedValue();
	return av * (1 - av);
}
