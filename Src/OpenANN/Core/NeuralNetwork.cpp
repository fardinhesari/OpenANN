#include "NeuralNetwork.h"

#include <utility>
#include "Matrix.h"
#include "vector"
#include "Layer.h"
#include "../Utils/MatrixMultiply.h"


NeuralNetwork::NeuralNetwork(vector<int> topology)
{
	topologySize = static_cast<int>(topology.size());
	this->topology = topology;

	for (int i = 0; i < topologySize; i++)
	{
		auto l = new Layer(topology.at(i));
		layers.push_back(l);
	}

	for (int i = 0; i < (topologySize - 1); i++)
	{
		auto m = new Matrix(topology.at(i), topology.at(i + 1), true);
		weightMatrices.push_back(m);
	}
}

void NeuralNetwork::setCurrentInput(vector<double> input)
{
	this->input = input;

	for (int i = 0; i < input.size(); i++)
	{
		layers.at(0)->setValue(i, input.at(i));
	}
}

void NeuralNetwork::printToConsole()
{
	for (int i = 0; i < layers.size(); i++)
	{
		cout << "Layer: " << i << endl;
		if (i == 0)
		{
			auto m = layers.at(i)->CreateMatrixOfValues();
			m->printToConsole();
		}
		else
		{
			auto m = layers.at(i)->CreateMatrixOfActivatedValues();
			m->printToConsole();
		}


		if (i < layers.size() - 1)
		{
			cout << endl << "Weights: " << endl;
			getWeightMatrix(i)->printToConsole();
		}
		cout << "---------------" << endl;
	}
}

void NeuralNetwork::feedForward()
{
	for (int i = 0; i < (layers.size() - 1); i++)
	{
		Matrix* a;

		if (i == 0)
		{
			a = getNeuronMatrix(i);
		}
		else
		{
			a = getActivatedNeuronMatrix(i);
		}

		auto b = getWeightMatrix(i);

		auto c = (new utils::MatrixMultiply(a, b))->execute();

		for (int j = 0; j < c->getNumberOfColumns(); j++)
		{
			setNeuronValue(i + 1, j, c->getValue(0, j));
		}
	}
}

void NeuralNetwork::setErrors()
{
	if(target.empty())
	{
		throw new exception("No Target for neural network");
	}
	
	if (target.size() != layers.at(layers.size() - 1)->getNeurons().size())
	{
		throw new exception("Target size differs from last layer size");
	}

	errors.clear();
	error = 0;
	int outputLayerIndex = layers.size() - 1;
	auto outputNeurons = layers.at(outputLayerIndex)->getNeurons();
	for (int i = 0; i < target.size(); i++)
	{
		double tempErr = outputNeurons.at(i)->getActivatedValue() - target.at(i);
		errors.push_back(tempErr);
		error += tempErr;
	}

	historicalErrors.push_back(error);
}
