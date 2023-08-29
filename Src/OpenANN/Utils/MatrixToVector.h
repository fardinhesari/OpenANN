#pragma once
#include "../Core/Matrix.h"

using namespace std;

namespace utils
{
class MatrixToVector
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="MatrixToVector"/> class.
	/// </summary>
	/// <param name="a">The matrix to be converted to vector</param>
	MatrixToVector(Matrix* a);

	/// <summary>
	/// Executes the convert.
	/// </summary>
	/// <returns>Result vector.</returns>
	vector<double>* execute() const;

private:

	Matrix* a;
};
	
}

