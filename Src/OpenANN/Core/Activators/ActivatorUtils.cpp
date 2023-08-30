#include "ActivatorUtils.h"

Activator* createActivatorByEnumType(Neuron* owner, const ActivatorType* type)
{
	/*switch (type)
	{
	case Sigmoid:
		return new SigmoidActivator(owner);
	case Tanh:
		return new TanhActivator(owner);
	case Relu:
		return new ReluActivator(owner);
	default:*/
		return new SigmoidActivator(owner);
	//}
}

Activator* createDefaultActivator(Neuron* owner)
{
	return new SigmoidActivator(owner);
}
