#include "Neuron.h"

#include "Activators/ActivatorUtils.h"

Neuron::Neuron(double val):Neuron(val, getDefaultActivatedValueFunctor(), getDefaultDerivedValueFunctor())
{}

Neuron::Neuron(double val, ActivatorType activatorType) : Neuron(val, getActivatedValueFunctorByEnumType(activatorType),
																		getDerivedValueFunctorByEnumType(activatorType))
{}

Neuron::Neuron(double val, getActivatedValueFunctor activator, getDerivedValueFunctor deriveActivator)
{
	this->activatedValueFunctor = activator;
	this->derivedValueFunctor = deriveActivator;

	setValue(val);
}


void Neuron::setValue(double val)
{
	this->value = val;
	activatedValue = activatedValueFunctor(value);
	derivedValue = derivedValueFunctor(value, derivedValue);
}
