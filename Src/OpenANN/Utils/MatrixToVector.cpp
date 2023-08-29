#include "MatrixToVector.h"

utils::MatrixToVector::MatrixToVector(Matrix* a)
{
	this->a = a;
}

vector<double>* utils::MatrixToVector::execute() const
{
	auto result = new vector<double>();

	for(int i = 0; i < a->getNumberOfRows(); i++)
	{
		for (int j = 0; j < a->getNumberOfColumns(); j++)
		{
			result->push_back(a->getValue(i, j));
		}
	}
	return result;
}
