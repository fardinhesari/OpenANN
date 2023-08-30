#include "Neuron.h"

#include "Activators/ActivatorUtils.h"

Neuron::Neuron(double val):Neuron(val, createDefaultActivator(this))
{}

Neuron::Neuron(double val, ActivatorType* activatorType) : Neuron(val, createActivatorByEnumType(this, activatorType))
{}

Neuron::Neuron(double val, Activator* activator)
{
	this->value = val;
	this->_activator = activator;
	setValue(val);
}

void Neuron::setValue(double val)
{
	this->value = val;
	activatedValue = _activator->getActivatedValue();
	derivedValue = _activator->getDerivedValue();
}
