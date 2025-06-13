#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T**& arr, const int rows, const int cols = 0);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index);

template<typename T>void push_col_back(T** arr, const int rows, int& cols);

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1


#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);

	int index;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows, cols);
#endif // DYNAMIC_MEMORY_2

}
template<typename T>T** Allocate(const int rows, const int cols)
{
	//1) ������ ������ ����������:
	T** arr = new T* [rows];

	//2) �������� ������ ��� ������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}
template<typename T>void Clear(T**& arr, const int rows, const int cols)
{
	//1) ������� ��������� ������ ���������� �������:

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2) ������ ������ ����� ������� ������ ����������:
	
	delete[] arr;
	//3) �������� ��������� �� ������:
	
	arr = nullptr;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; // ����� ���������� ���������� � �������� �������������
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; // ����� ���������� ���������� � �������� �������������
		arr[i] /= 100;
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
template<typename T> void Print(T arr[], const int n)
{
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t"; // ����� �������� �������������� (Subscript operator)
	}
}
template<typename T> void Print(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	//1) ������ �������� ������ ���������� ������� �������:
	T** buffer = new T* [rows + 1];

	//2) �������� ������ ����� � ����� ������:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ������� �������� ������ ����������:
	delete[] arr;

	//4) ��������� ����������� ������:
	buffer[rows] = new T[cols] {};

	//5) ����� ���������� ������, ���������� ����� ����. �� 1:
	rows++;

	//6)) ���������� ����� ������:
	return buffer;
}
template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	if (index < 0 || index > rows)
	{
		cout << "Error: Out of range exception" << endl;
		return arr;
	}
	T** buffer = new T* [rows + 1] {};
	//for (int i = 0; i < index; i++)buffer[i] = arr[i];
	//for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	for (int i = 0; i < rows; i++)
	{
		//if (i < index)buffer[i] = arr[i];
		//else buffer[i + 1] = arr[i];
		//i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) ������ �������� ������ ������� �������: 
		T* buffer = new T[cols + 1] {};
		//2) �������� �������� �� �������� ������ � ��������:
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) ������� �������� ������:
		delete[] arr[i];
		//4) ��������� ����� �������� ������ ������� ����� ������:
		arr[i] = buffer;
	}
	cols++;
}