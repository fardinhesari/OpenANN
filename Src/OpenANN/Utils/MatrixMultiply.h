#pragma once
#include "../Core/Matrix.h"

using namespace std;

namespace utils
{
	
class MatrixMultiply
{
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="MatrixMultiply"/> class.
	/// </summary>
	/// <param name="a">Left Matrix.</param>
	/// <param name="b">Right Matrix.</param>
	MatrixMultiply(Matrix* a, Matrix* b);

	/// <summary>
	/// Executes the multiplication of 2 matrices.
	/// </summary>
	/// <returns>A new matrix.</returns>
	Matrix* execute();

private:
	Matrix* a;
	Matrix* b;
	Matrix* c;
};

}

