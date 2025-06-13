#include <iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	//Подсчёт количества элементов:
	int even_count = 0;	//количество чётных элементов
	int odd_count = 0;	//количество нечётных элементов

	for (int i = 0; i < n; i++)
	{
		(arr[i] % 2 ? odd_count : even_count)++;
	}
	cout << "Количество чётных элементов: " << even_count << endl;
	cout << "Количество нечётных элементов: " << odd_count << endl;

	//Выделение памяти под массивы:
	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	//Копирование чётных и нечётных элементов в массивы:
	for (int i = 0, j = 0, k = 0; i < n; i++)
	{
		(arr[i] % 2 ? odd_arr[j++] : even_arr[k++]) = arr[i];
	}

	//Вывод массивов:
	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

	//Удаление динамических массивов:
	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}