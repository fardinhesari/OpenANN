#pragma once

#include <iostream>

using namespace  std;


/// <summary>
/// Basic class for a neuron
/// </summary>
class Neuron
{
public:


	/// <summary>
	/// Initializes a new instance of the <see cref="Neuron"/> class.
	/// </summary>
	/// <param name="val">The value of Neuron.</param>
	Neuron(double val);

	/// <summary>
	/// Fast sigmoid function.\n
	///	f(x) = x / (1 + |x|)
	/// </summary>
	void activate();

	/// <summary>
	/// Derivative of neuron.\n
	///	f'(x) = f(x) * (1 - f(x)).
	/// </summary>
	void derive();


	/// <summary>
	/// Gets the value.
	/// </summary>
	/// <returns></returns>
	double getValue() const
	{
		return value;
	}

	/// <summary>
	/// Gets the activated value.
	/// </summary>
	/// <returns></returns>
	double getActivatedValue() const
	{
		return activatedValue;
	}

	/// <summary>
	/// Gets the derived value.
	/// </summary>
	/// <returns></returns>
	double getDerivedValue() const
	{
		return derivedValue;
	}

private:
	/// <summary>
	/// The real value of neuron.
	/// </summary>
	double value;

	/// <summary>
	/// The value passed to next neurons.\n
	///	Value between 0 and 1.
	/// </summary>
	double activatedValue;


	/// <summary>
	/// The derivative of current neuron.
	/// </summary>
	double derivedValue;

};
