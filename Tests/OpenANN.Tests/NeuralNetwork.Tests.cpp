#include "pch.h"
#include "CppUnitTest.h"
#include "../../Src/OpenANN/Matrix.h"
//#include "../../Src/OpenANN/NeuralNetwork.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OpenANNTests
{
	TEST_CLASS(OpenANNTestsMatrix2)
	{
	public:

		TEST_METHOD(MatrixClassShouldInitializeAndEqualToTransposeOfTranspose)
		{
			auto m = new Matrix(4, 5, true);
			auto mT = m->transpose();
			auto mTT = mT->transpose();
			for (int i = 0; i < m->getNumberOfRows(); i++)
			{
				for (int j = 0; j < m->getNumberOfColumns(); j++)
				{
					Assert::AreEqual(m->getValue(i, j), mTT->getValue(i, j));
				}
			}
		}
	};
}


