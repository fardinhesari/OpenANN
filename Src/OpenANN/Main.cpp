#include <iostream>

#include "Neuron.h"

using namespace std;

int main(int argc, char** argv)
{
	auto* n = new Neuron(0.9);

	cout << n->getValue() << endl;
	cout << (*n).getActivatedValue() << endl;
	cout << n->getDerivedValue() << endl;


	return 0;
}