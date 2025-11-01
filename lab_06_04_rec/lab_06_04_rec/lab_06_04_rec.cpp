#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <ctime> 

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX, int i = 0)
{
	if (i == SIZE)
	{
		return;
	}
	arr[i] = (MAX - MIN) * rand() / RAND_MAX + MIN;
	create(arr, SIZE, MIN, MAX, i + 1);
}

void print(int* arr, int SIZE, int i = 0)
{
	if (i == SIZE)
	{
		return;
	}
	cout << arr[i] << " ";
	print(arr, SIZE, i + 1);
}

int MaxRecursive(int* arr, int SIZE, int i, int currentMax)
{
	if (i == SIZE)
	{
		return currentMax;
	}

	if (arr[i] > currentMax)
	{
		return MaxRecursive(arr, SIZE, i + 1, arr[i]);
	}
	else
	{
		return MaxRecursive(arr, SIZE, i + 1, currentMax);
	}
}

int Max(int* arr, int SIZE)
{
	if (SIZE == 0) return 0;
	return MaxRecursive(arr, SIZE, 1, arr[0]);
}

int MaxIndexRecursive(int* arr, int SIZE, int i, int currentMaxIndex)
{
	if (i == SIZE)
	{
		return currentMaxIndex;
	}

	if (arr[i] > arr[currentMaxIndex])
	{
		return MaxIndexRecursive(arr, SIZE, i + 1, i);
	}
	else
	{
		return MaxIndexRecursive(arr, SIZE, i + 1, currentMaxIndex);
	}
}

int MaxIndex(int* arr, int SIZE)
{
	if (SIZE == 0) return -1;
	return MaxIndexRecursive(arr, SIZE, 1, 0);
}

long long PBZRecursive(int* arr, int SIZE, int i, int zeroCount, long long product)
{
	if (i == SIZE)
	{
		return (zeroCount < 2) ? 0 : product;
	}

	if (zeroCount == 2)
	{
		return product;
	}

	if (arr[i] == 0)
	{
		return PBZRecursive(arr, SIZE, i + 1, zeroCount + 1, product);
	}
	else if (zeroCount == 1)
	{
		return PBZRecursive(arr, SIZE, i + 1, zeroCount, product * arr[i]);
	}
	else
	{
		return PBZRecursive(arr, SIZE, i + 1, zeroCount, product);
	}
}

long long PBZ(int* arr, int SIZE)
{
	return PBZRecursive(arr, SIZE, 0, 0, 1);
}

int CopyEvenRecursive(int* arr, int* tempArr, int SIZE, int readInd, int writeInd)
{
	if (readInd >= SIZE)
	{
		return writeInd;
	}

	tempArr[writeInd] = arr[readInd];
	return CopyEvenRecursive(arr, tempArr, SIZE, readInd + 2, writeInd + 1);
}

void CopyOddRecursive(int* arr, int* tempArr, int SIZE, int readInd, int writeInd)
{
	if (readInd >= SIZE)
	{
		return;
	}

	tempArr[writeInd] = arr[readInd];
	CopyOddRecursive(arr, tempArr, SIZE, readInd + 2, writeInd + 1);
}

void CopyBackRecursive(int* arr, int* tempArr, int SIZE, int i)
{
	if (i == SIZE)
	{
		return;
	}

	arr[i] = tempArr[i];
	CopyBackRecursive(arr, tempArr, SIZE, i + 1);
}

void RearrArray(int* arr, int SIZE)
{
	int* tempArr = new int[SIZE];

	int nextWriteIndex = CopyEvenRecursive(arr, tempArr, SIZE, 0, 0);

	CopyOddRecursive(arr, tempArr, SIZE, 1, nextWriteIndex);

	CopyBackRecursive(arr, tempArr, SIZE, 0);

	delete[] tempArr;
}

int main()
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int MIN, MAX;
	int SIZE;

	cout << "Розмір масиву: "; cin >> SIZE;
	cout << "Введіть діапазон (MIN): "; cin >> MIN;
	cout << "Введіть діапазон (MAX): "; cin >> MAX;
	cout << endl;

	int* arr = new int[SIZE];

	create(arr, SIZE, MIN, MAX);

	print(arr, SIZE);
	cout << endl;
	cout << "Максимальне у масиві: " << Max(arr, SIZE) << endl;
	cout << "Номер максимального у масиві: " << MaxIndex(arr, SIZE) + 1 << endl;
	cout << "Добуток елементів масиву між нулями: " << PBZ(arr, SIZE) << endl;

	RearrArray(arr, SIZE);
	cout << "Перетворений масив: "; print(arr, SIZE);
	cout << endl;

	delete[] arr;
	return 0;
}