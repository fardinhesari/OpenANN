#pragma once
#include "ActivatorTypes.h"


Activator* createActivatorByEnumType(Neuron* owner, const ActivatorType* type);

Activator* createDefaultActivator(Neuron* owner);


