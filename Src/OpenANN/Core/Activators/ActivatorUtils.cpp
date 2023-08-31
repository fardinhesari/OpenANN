#include <math.h>

#include "ActivatorUtils.h"

#include <valarray>

double f1(double& value)
{
	return 1.2;
}

getActivatedValueFunctor getActivatorByEnumType(ActivatorType type)
{
	switch (type)
	{
	case Sigmoid:
		return [](double& value) {return 1 / (1 + std::exp(value)); };
	case Tanh:
		return [](double& value) {return std::tanh(value); };
	case Relu:
		return [](double& value)
		{
			if (value > 0) return value;
			return 0;
		};
	}
}

getActivatedValueFunctor getDefaultActivatedValueFunctor()
{
	return getActivatorByEnumType(Sigmoid);
}

getDerivedValueFunctor getDerivedValueFunctorByEnumType(ActivatorType type)
{
	switch (type)
	{
	case Sigmoid:
		return [](double& value, double& activatedValue) {return activatedValue * (1 - activatedValue); };
	case Tanh:
		return [](double& value, double& activatedValue){return 1 - std::pow(activatedValue, 2); };
	case Relu:
		return [](double& value, double& activatedValue)
		{
			if (value > 0) return 1.0;
			return 0.0;
		};
	}
}


