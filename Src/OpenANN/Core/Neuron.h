#pragma once

#include "Activators/ActivatorTypes.h"
#include "Activators/ActivatorUtils.h"

using namespace  std;

/// <summary>
/// Basic class for a neuron
/// </summary>
class Neuron
{
public:


	/// <summary>
	/// Initializes a new instance of the <see cref="Neuron"/> class with default sigmoid activator.
	/// </summary>
	/// <param name="val">The value of Neuron.</param>
	Neuron(double val);

	/// <summary>
	/// Initializes a new instance of the <see cref="Neuron"/> class with specified activator.
	/// </summary>
	/// <param name="val">The value.</param>
	/// <param name="activator">The activator object.</param>
	Neuron(double val, getActivatedValueFunctor activator, getDerivedValueFunctor deriveActivator);

	/// <summary>
	/// Initializes a new instance of the <see cref="Neuron"/> class based on specified activator.
	/// </summary>
	/// <param name="val">The value.</param>
	/// <param name="activatorType">Type of the activator.</param>
	Neuron(double val, ActivatorType activatorType);

	/// <summary>
	/// Gets the value.
	/// </summary>
	/// <returns></returns>
	double getValue() const	{return value;}

	/// <summary>
	/// Gets the activated value.
	/// </summary>
	/// <returns></returns>
	double getActivatedValue() const {return activatedValue;}

	/// <summary>
	/// Gets the derived value.
	/// </summary>
	/// <returns></returns>
	double getDerivedValue() const {return derivedValue;}

	/// <summary>
	/// Sets the value of neuron and updates derived and activated values by activator obejct.
	/// </summary>
	/// <param name="value">The value.</param>
	void setValue(double value);
private:
	double value;

	double activatedValue;

	double derivedValue;

	getActivatedValueFunctor activatedValueFunctor;

	getDerivedValueFunctor derivedValueFunctor;

};

