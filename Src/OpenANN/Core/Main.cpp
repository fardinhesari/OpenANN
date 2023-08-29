#include <iostream>

#include "Matrix.h"
#include "NeuralNetwork.h"
#include "Neuron.h"

using namespace std;

int main(int argc, char** argv)
{
	vector<int> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);

	vector<double> input;
	input.push_back(1.0);
	input.push_back(0.0);
	input.push_back(1.0);

	auto nn = new NeuralNetwork(topology);
	nn->setCurrentInput(input);

	cout << "Initial Matrix:" << endl;
	nn->printToConsole();

	cout << "--------------" << endl << "New Matrix:" << endl;
	nn->feedForward();
	nn->printToConsole();

	return 0;
}