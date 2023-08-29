#include "Layer.h"

Layer::Layer(int size)
{
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		Neuron* n = new Neuron(0.0);
		neurons.push_back(n);
	}
}

void Layer::setValue(int index, double value)
{
	neurons.at(index)->setValue(value);
}

Matrix* Layer::CreateMatrixOfValues()
{
	auto m = new Matrix(1, size, false);

	for (int i = 0; i < size; i++)
	{
		m->setValue(0, i, neurons.at(i)->getValue());
	}

	return m;
}

Matrix* Layer::CreateMatrixOfActivatedValues()
{
	auto m = new Matrix(1, size, false);

	for (int i = 0; i < size; i++)
	{
		m->setValue(0, i, neurons.at(i)->getActivatedValue());
	}

	return m;
}

Matrix* Layer::CreateMatrixOfDerivedValues()
{
	auto m = new Matrix(1, size, false);

	for (int i = 0; i < size; i++)
	{
		m->setValue(0, i, neurons.at(i)->getDerivedValue());
	}

	return m;
}
