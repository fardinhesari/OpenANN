#include <iostream>

//#include "Matrix.h"
//#include "NeuralNetwork.h"
//#include "Neuron.h"

using namespace std;

int main(int argc, char** argv)
{
	/*vector<int> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(3);

	vector<double> input;
	input.push_back(1.0);
	input.push_back(0.0);
	input.push_back(1.0);

	auto nn = new NeuralNetwork(topology);
	nn->setCurrentInput(input);
	nn->setCurrentTarget(input);

	cout << "Initial Matrix:" << endl;
	nn->printToConsole();

	cout << "--------------" << endl << "New Matrix:" << endl;

	int counter = 0;
	do
	{
		counter++;
		nn->feedForward();
		cout << "Epoch:\t" << counter << endl;
		nn->setErrors();
		nn->backPropagate();
		cout << endl << endl << "Error:\t" << nn->getError() << endl;
	} while (abs(nn->getError()) > 0.05);

	nn->printToConsole();*/

	return 0;
}