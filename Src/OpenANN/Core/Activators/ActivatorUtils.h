#pragma once
#include "ActivatorTypes.h"

using getActivatedValueFunctor = double(*)(double&);
using getDerivedValueFunctor = double(*)(double& value, double& activatedValue);

getActivatedValueFunctor getActivatedValueFunctorByEnumType(ActivatorType type);

getActivatedValueFunctor getDefaultActivatedValueFunctor();

getDerivedValueFunctor getDerivedValueFunctorByEnumType(ActivatorType type);

getDerivedValueFunctor getDefaultDerivedValueFunctor();


