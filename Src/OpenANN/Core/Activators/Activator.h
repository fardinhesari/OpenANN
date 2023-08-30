#pragma once
#include "../Neuron.h"


class Activator
{
public:
	//Activator();

	explicit Activator(Neuron* owner)
		: owner(owner){}

	virtual double getActivatedValue() = 0;
	virtual double getDerivedValue() = 0;

protected:
	Neuron* owner;
};

