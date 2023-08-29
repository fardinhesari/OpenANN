#include "pch.h"
#include "CppUnitTest.h"
#include "../../Src/OpenANN/Neuron.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OpenANNTests
{
	TEST_CLASS(NeuronClassTests)
	{
	public:

		TEST_METHOD(NeuronClassShouldInitializeRightWithGivenValue)
		{
			Neuron n1(0.9);
			Assert::AreEqual(n1.getValue(), 0.9);

			Neuron n2(1);
			Assert::AreEqual(n2.getActivatedValue(), 0.5);
			Assert::AreEqual(n2.getDerivedValue(), 0.25);
		}

	};
}
