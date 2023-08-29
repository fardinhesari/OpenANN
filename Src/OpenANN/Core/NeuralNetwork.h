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

	
	void setCurrentTarget(vector<double> target){ this->target = std::move(target); }

	void printToConsole();

	Matrix* getNeuronMatrix(int index) const { return layers.at(index)->CreateMatrixOfValues(); }

	Matrix* getActivatedNeuronMatrix(int index) const { return layers.at(index)->CreateMatrixOfActivatedValues(); }

	Matrix* getDerivedNeuronMatrix(int index) const { return layers.at(index)->CreateMatrixOfDerivedValues(); }

	Matrix* getWeightMatrix(int index) const { return weightMatrices.at(index); }

	void setNeuronValue(int layerIndex, int neuronIndex, double value) { layers.at(layerIndex)->setValue(neuronIndex, value); }

	/// <summary>
	/// Feeds forward the neural network one iteration.
	/// </summary>
	void feedForward();

	/// <summary>
	/// Sets the errors.
	/// </summary>
	void setErrors();

	double getError() const { return error; }

	vector<double> getErrors() { return errors; }

private:
	int topologySize;

	vector<int> topology;

	vector<Layer*> layers;

	vector<Matrix*> weightMatrices;

	vector<double> input;

	vector<double> target;

	double error;

	vector<double> errors;

	vector<double> historicalErrors;

};

