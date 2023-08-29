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

	c = new Matrix(a->getNumberOfRows(), b->getNumberOfColumns(), false);
}

Matrix* utils::MatrixMultiply::execute()
{
	for (int i = 0; i < a->getNumberOfRows(); i++)
	{
		for (int j = 0; j < b->getNumberOfColumns(); j++)
		{
			for (int k = 0; k < b->getNumberOfColumns(); k++)
			{
				auto p = a->getValue(i, k) * b->getValue(k, j);
				auto newVal = c->getValue(i, j) + p;
				c->setValue(i, j, newVal);
			}
		}
	}

	return this->c;
}
