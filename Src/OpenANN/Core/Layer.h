#pragma once
#include <vector>

#include "Matrix.h"
#include "Neuron.h"

using namespace std;

class Layer
{
public:

	/// <summary>
	/// Initializes a new instance of the <see cref="Layer"/> class with specified number of neurons.
	/// </summary>
	/// <param name="size">The number of neurons in layer..</param>
	Layer(int size);

	/// <summary>
	/// Sets the value for given index
	/// </summary>
	/// <param name="index">The index.</param>
	/// <param name="value">The value.</param>
	void setValue(int index, double value);

	/// <summary>
	/// Creates the matrix corresponding to values.
	/// </summary>
	/// <returns></returns>

	Matrix* CreateMatrixOfValues();

	/// <summary>
	/// Creates the matrix of activated values.
	/// </summary>
	/// <returns></returns>
	Matrix* CreateMatrixOfActivatedValues();

	/// <summary>
	/// Creates the matrix of derived values.
	/// </summary>
	/// <returns></returns>
	Matrix* CreateMatrixOfDerivedValues();

	

private:
	/// <summary>
	/// The size of layer.
	/// </summary>
	int size;


	/// <summary>
	/// The neuron objects' vector
	/// </summary>
	vector<Neuron*> neurons;

};

