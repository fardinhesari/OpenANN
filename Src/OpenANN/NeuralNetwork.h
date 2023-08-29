#pragma once
#include "Matrix.h"
#include "Layer.h"

using namespace std;

class NeuralNetwork
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="NeuralNetwork"/> class with the given topolgy
	/// </summary>
	/// <param name="topology">The topology of the neural network.</param>
	NeuralNetwork(vector<int> topology);

	/// <summary>
	/// Sets the current input of neural network with given vector values.
	/// </summary>
	/// <param name="input">The input values.</param>
	void setCurrentInput(vector<double> input);

	void printToConsole();


private:
	int topologySize;
	vector<int> topology;

	vector<Layer*> layers;

	vector<Matrix*> weightMatrices;

	vector<double> input;
};

