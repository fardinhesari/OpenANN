#include "NeuralNetwork.h"

#include <utility>
#include <algorithm>
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

void NeuralNetwork::backPropagate()
{  
	vector<Matrix*> newWeights;
	Matrix* gradient;

	int outputLayerIndex = layers.size() - 1;
	auto derivedValuesYtoZ= layers.at(outputLayerIndex)->CreateMatrixOfDerivedValues();
	auto gradientsYtoZ = new Matrix(1, layers.at(outputLayerIndex)->getNeurons().size(), false);

	for (int i = 0; i < errors.size(); i++)
	{
		double d = derivedValuesYtoZ->getValue(0, i);
		double e = errors.at(i);
		double g = d * e;
		gradientsYtoZ->setValue(0, i, g);
	}

	int lastHiddenLayerIndex			 = outputLayerIndex - 1;
	auto lastHiddenLayer				 = layers.at(lastHiddenLayerIndex);
	auto weightsOutputToHidden	 = weightMatrices.at(outputLayerIndex - 1);
	auto deltaOutputToHidden		 = (new utils::MatrixMultiply(gradientsYtoZ->transpose(), lastHiddenLayer->CreateMatrixOfActivatedValues()))->execute()->transpose();

	auto newWeightsOutputToHidden		 = new Matrix(deltaOutputToHidden->getNumberOfRows(),
												deltaOutputToHidden->getNumberOfColumns(),
												false);

	for (int r = 0; r < deltaOutputToHidden->getNumberOfRows(); r++)
	{
		for (int c = 0; c < deltaOutputToHidden->getNumberOfColumns(); c++)
		{
			double originalWeight = weightsOutputToHidden->getValue(r, c);
			double deltaWeight = deltaOutputToHidden->getValue(r, c);
			newWeightsOutputToHidden->setValue(r, c, (originalWeight - deltaWeight));
		}
	}

	newWeights.push_back(newWeightsOutputToHidden);
	gradient = new Matrix(gradientsYtoZ->getNumberOfRows(), gradientsYtoZ->getNumberOfColumns(), false);

	for (int r = 0; r < gradientsYtoZ->getNumberOfRows(); r++)
	{
		for (int c = 0; c < gradientsYtoZ->getNumberOfColumns(); c++)
		{
			gradient->setValue(r, c, gradientsYtoZ->getValue(r, c));
		}
	}

	for (int i = lastHiddenLayerIndex; i > 0; i--)
	{
		auto l = layers.at(i);
		auto derivedHidden = l->CreateMatrixOfDerivedValues();
		auto activatedHidden = l->CreateMatrixOfActivatedValues();
		auto derivedGradients = new Matrix(1, l->getNeurons().size(), 1);
		auto weightMatrix = weightMatrices.at(i);
		auto originalWeight = weightMatrices.at(i - 1);

		for (int r = 0; r < weightMatrix->getNumberOfRows(); r++)
		{
			double sum = 0;
			for (int c = 0; c < weightMatrix->getNumberOfColumns(); c++)
			{
				sum += gradient->getValue(0, c)* weightMatrix->getValue(r, c);
			}
			double g = sum * activatedHidden->getValue(0, r);
			derivedGradients->setValue(0, r, g);
		}

		auto leftneurons = i == 1 ? layers.at(0)->CreateMatrixOfValues() : layers.at(i - 1)->CreateMatrixOfActivatedValues();
		auto deltaWeights = (new utils::MatrixMultiply(derivedGradients->transpose(), leftneurons))->execute()->transpose();

		auto newWeightsHidden = new Matrix(deltaWeights->getNumberOfRows(), deltaWeights->getNumberOfColumns(), false);

		for (int r = 0; r < newWeightsHidden->getNumberOfRows(); r++)
		{
			for (int c = 0; c < newWeightsHidden->getNumberOfColumns(); c++)
			{
				double w = originalWeight->getValue(r, c);
				double d = deltaWeights->getValue(r, c);
				double n = w - d;
				newWeightsHidden->setValue(r, c, n);
			}
		}
		
		newWeights.push_back(newWeightsHidden);

		gradient = new Matrix(derivedGradients->getNumberOfRows(), derivedGradients->getNumberOfColumns(), false);

		for (int r = 0; r < derivedGradients->getNumberOfRows(); r++)
		{
			for (int c = 0; c < derivedGradients->getNumberOfColumns(); c++)
			{
				gradient->setValue(r, c, derivedGradients->getValue(r, c));
			}
		}

		reverse(newWeights.begin(), newWeights.end());

		weightMatrices = newWeights;
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
