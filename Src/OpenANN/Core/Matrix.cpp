#include "Matrix.h"

#include <iomanip>
#include <iostream>
#include <random>

Matrix::Matrix(int numRows, int numCols, bool isRandom)
{
	this->numRows = numRows;
	this->numCols = numCols;

	for (int i = 0; i < numRows; i++)
	{
		vector<double> colValues;

		for (int j = 0; j < numCols; j++)
		{
			double r = 0.0;
			if (isRandom)
			{
				r = generateRandomNumber();
			}
			colValues.push_back(r);
		}
		values.push_back(colValues);
	}
}

Matrix* Matrix::transpose() const
{
	auto mT = new Matrix(numCols, numRows, false);
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			mT->setValue(j, i, getValue(i, j));
		}
	}
	return mT;
}

void Matrix::printToConsole()
{
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			cout << setprecision(5) << values.at(i).at(j) << resetiosflags(0) << "     ";
		}
		cout << endl;
	}
}


double Matrix::generateRandomNumber() noexcept
{
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> dis(0, 1);
	return dis(gen);
}
