#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = (MAX - MIN) * rand() / RAND_MAX + MIN;
	}
}

void print(int* arr, int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}
}

int Max(int* arr, int SIZE)
{
	int maximal = arr[0];
	for (int i = 1; i < SIZE; i++)
		if (arr[i] > maximal)
			maximal = arr[i];
	return maximal;
}

int MaxIndex(int* arr, int SIZE)
{
	int maximal = arr[0];
	int maxindex = 0;
	for (int i = 1; i < SIZE; i++)
		if (arr[i] > maximal)
		{
			maximal = arr[i];
			maxindex = i;
		}
	return maxindex;
}

long long PBZ(int* arr, int SIZE)
{
	long long product = 1;
	int zeroCount = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			zeroCount++;
			if (zeroCount == 2)
			{
				break;
			}
		}
		else if (zeroCount == 1)
		{
			product *= arr[i];
		}
	}
	if (zeroCount < 2)
	{
		return 0;
	}
	return product;
}

void RearrArray(int* arr, int SIZE)
{
	int* tempArr = new int[SIZE];
	int tempInd = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 == 0) // якщо як програміст то !=
		{
			tempArr[tempInd] = arr[i];
			tempInd++;
		}
			
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (i % 2 != 0) // якщо як програміст то ==
		{
			tempArr[tempInd] = arr[i];
			tempInd++;
		}
			
	}
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = tempArr[i];
	}
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
	cout << "Номер максимального у масиві: " << MaxIndex(arr, SIZE) + 1 << endl; // якщо як програміст то без + 1
	cout << "Добуток елементів масиву між нулями: " << PBZ(arr, SIZE) << endl;

	RearrArray(arr, SIZE);
	cout << "Перетворений масив: "; print(arr, SIZE);
	cout << endl;

	delete[] arr;
	return 0;
}