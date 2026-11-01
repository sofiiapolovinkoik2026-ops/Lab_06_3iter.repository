#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_3iter/Lab_06_3iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIter
{
	TEST_CLASS(UnitTestIter)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int arr1[5] = { 20, 15, 15, 10, 2 };
			int arr2[5] = { 20, 15, 18, 10, 2 };

			// Перевірка звичайної функції
			Assert::IsTrue(IsNonIncreasing(arr1, 5));
			Assert::IsFalse(IsNonIncreasing(arr2, 5));

			// Перевірка шаблонної функції
			double arrDouble[4] = { 5.5, 4.3, 2.1, 0.0 };
			Assert::IsTrue(IsNonIncreasing<double>(arrDouble, 4));
		}
	};
}