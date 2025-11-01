#include "pch.h"
#include "CppUnitTest.h"
#include "F:\Project\lab_06_04_rec\lab_06_04_rec\lab_06_04_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest_RecursiveArrayOps
{
	TEST_CLASS(RecursiveArrayTests)
	{
	public:

		TEST_METHOD(Test_Max_FindsLargestValue)
		{
			const int SIZE = 5;
			int arr[SIZE] = { 10, 5, 20, 2, 15 };

			int expected_max = 20;
			int actual_max = Max(arr, SIZE);

			Assert::AreEqual(expected_max, actual_max, L"Max не знайшла правильне максимальне значення.");
		}

		TEST_METHOD(Test_MaxIndex_FindsCorrectIndex)
		{
			const int SIZE = 5;
			int arr[SIZE] = { 10, 5, 20, 2, 15 };

			int expected_index = 2;
			int actual_index = MaxIndex(arr, SIZE);

			Assert::AreEqual(expected_index, actual_index, L"MaxIndex не знайшла правильний індекс.");
		}

		TEST_METHOD(Test_PBZ_StandardCase)
		{
			const int SIZE = 7;
			int arr[SIZE] = { 1, 0, 5, 10, 0, 20, 1 };

			long long expected_product = 50LL;
			long long actual_product = PBZ(arr, SIZE);

			Assert::AreEqual(expected_product, actual_product, L"PBZ (стандартний випадок) обчислено невірно.");
		}

		TEST_METHOD(Test_PBZ_LessThanTwoZeros)
		{
			const int SIZE = 5;
			int arr[SIZE] = { 1, 0, 5, 10, 20 };

			long long expected_product = 0LL;
			long long actual_product = PBZ(arr, SIZE);

			Assert::AreEqual(expected_product, actual_product, L"PBZ (менше двох нулів) має повертати 0.");
		}

		TEST_METHOD(Test_RearrArray_SortsEvenOddIndices)
		{
			const int SIZE = 5;
			int arr[SIZE] = { 10, 5, 20, 0, 7 };

			int expected_arr[SIZE] = { 10, 20, 7, 5, 0 };

			RearrArray(arr, SIZE);

			for (int i = 0; i < SIZE; ++i)
			{
				Assert::AreEqual(expected_arr[i], arr[i], L"Масив не був коректно пересортований.");
			}
		}
	};
}