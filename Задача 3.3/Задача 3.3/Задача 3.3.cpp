﻿#include <iostream>
#include <time.h>
#include <stdlib.h>

const int sizeArray = 15; // размер массива
const int randomNumbRange = 4; // диапазон случайных чисел

void generationArray(int arrayOfNumbers[]) // функция, которая принимает массив и заполняет его случайными значениями
{
	for (int i = 0; i != sizeArray; i++)
	{
		arrayOfNumbers[i] = rand() % randomNumbRange;
	}
}

void printArray(int arrayOfNumbers[]) // вывод элементов массива на экран
{
	for (int i = 0; i != sizeArray; i++)
	{
		printf("%d\n", arrayOfNumbers[i]);
	}
}

void insertSortArray(int arrayOfNumbers[], int first, int last) // алгоритм сортировки вставками
{
	for (int i = first + 1; i != last + 1; ++i)
	{
		int j = i;
		while (j > 1 && arrayOfNumbers[j] < arrayOfNumbers[j - 1])
		{
			int temp = arrayOfNumbers[j];
			arrayOfNumbers[j] = arrayOfNumbers[j - 1];
			arrayOfNumbers[j - 1] = temp;
			--j;
		}
	}

}

int partition(int arrayOfNumbers[], int first, int last) // функция нахождения разделителя
{
	int temporaryPivot = arrayOfNumbers[first]; // элемент, являющийся разделителем
	int i = first;
	int j = i;
	for (i = first + 1; i != last + 1; ++i)
	{
		if (arrayOfNumbers[i] <= temporaryPivot)
		{
			++j;
			int temp = arrayOfNumbers[j];
			arrayOfNumbers[j] = arrayOfNumbers[i];
			arrayOfNumbers[i] = temp;
		}
	}
	int temp = arrayOfNumbers[first];
	arrayOfNumbers[first] = arrayOfNumbers[j];
	arrayOfNumbers[j] = temp;
	return j;
}

void qSortArray(int arrayOfNumbers[], int first, int last) // алгоритм быстрой сортировки
{
	if (first >= last)
	{
		return;
	}
	if (last - first < 10) // если элементов в куске массива меньше 10, то
	{
		insertSortArray(arrayOfNumbers, first, last); // вызываем процедуру алгоритма вставками
	}
	else
	{
		int pivot = partition(arrayOfNumbers, first, last); // разделитель
		qSortArray(arrayOfNumbers, first, pivot - 1);
		qSortArray(arrayOfNumbers, pivot + 1, last);
	}
}

int oftenElement(int arrayOfNumbers[]) // функция, возвращающая наиболее часто встречающийся элемент
{
	int counter = 0;
	int maxCounter = 0;
	int tempOftenElement = arrayOfNumbers[1];
	for (int i = 0; i != sizeArray - 1; ++i)
	{
		if (arrayOfNumbers[i] == arrayOfNumbers[i + 1])
		{
			++counter;
		}
		else
		{
			if (counter > maxCounter)
			{
				maxCounter = counter;
				tempOftenElement = arrayOfNumbers[i];
			}
			counter = 0;
		}
	}
	return tempOftenElement;
}

bool testQSort(int testArray[], int correctArray[])
{
	qSortArray(testArray, 0, sizeArray - 1);
	for (int i = 0; i != sizeArray; ++i)
	{
		if (testArray[i] != correctArray[i])
		{
			return false;
		}
	}
	return true;
}

bool testOftenElement(int testArray[], int correctElement)
{
	qSortArray(testArray, 0, sizeArray - 1);
	return oftenElement(testArray) == correctElement;
}

int main()
{
	int sortTestArray[] = { 0, 3, 4, 1, 2, 10, 9, 8, 11, 5, 12, 7, 6, 14, 13 };
	int sortTestCorrectArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };

	if (!testQSort(sortTestArray, sortTestCorrectArray))
	{
		printf("qsort test failed\n");
	}

	int oftenTestArray[] = { 0, 3, 3, 1, 2, 1, 2, 1, 1, 5, 12, 1, 3, 1, 13 };
	int correctOften = 1;

	if (!testOftenElement(oftenTestArray, correctOften))
	{
		printf("oftenElement test failed");
	}

	int arrayOfNumbers[sizeArray];

	printf("Array:\n");
	generationArray(arrayOfNumbers);
	printArray(arrayOfNumbers);

	qSortArray(arrayOfNumbers, 0, sizeArray - 1);

	printf("The most often element: %d\n", oftenElement(arrayOfNumbers));

	return 0;
}