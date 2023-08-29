#include "NeuralNetwork.h"
#include "Matrix.h"
#include "vector"
#include "Layer.h"


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
	}
}

void NeuralNetwork::feedForward()
{
	for (int i = 0; i < (layers.size() - 1); i++)
	{
	}
}
