#include "MatrixMultiply.h"

#include <iostream>

utils::MatrixMultiply::MatrixMultiply(Matrix* a, Matrix* b)
{
	this->a = a;
	this->b = b;

	if (a->getNumberOfColumns() != b->getNumberOfRows())
	{
		throw new exception("Unmatching matrix dimensions!!");
	}

	c = new Matrix(a->getNumberOfRows(), a->getNumberOfColumns(), false);
}

Matrix* utils::MatrixMultiply::execute()
{
	for (int i = 0; i < a->getNumberOfRows(); i++)
	{
		for (int j = 0; j < )
	}

	return this->c;
}
