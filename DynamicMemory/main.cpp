#include <iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int** push_row_back(int** arr, int& rows, const int cols);

void push_col_back(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMEORY_1
#define DYNAMIC_MEMEORY_2

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

	int rows;
	int cols;
	cout << "������� ���������� �����: "; cin >> rows;
	cout << "������� ���������� ��������� ������: "; cin >> cols;
	
	//1) ������ ������ ����������:
	int** arr = new int* [rows];

	//2) �������� ������ ��� ������:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
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
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; // ����� ���������� ���������� � �������� �������������
	}
}
void Print(int** arr, const int rows, const int cols)
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
void Print(int arr[], const int n)
{
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t"; // ����� �������� �������������� (Subscript operator)
	}
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) ������ �������� ������ ���������� ������� �������:
	int** buffer = new int* [rows + 1];

	//2) �������� ������ ����� � ����� ������:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	//3) ������� �������� ������ ����������:
	delete[] arr;

	//4) ��������� ����������� ������:
	buffer[rows] = new int[cols] {};

	//5) ����� ���������� ������, ���������� ����� ����. �� 1:
	rows++;

	//6)) ���������� ����� ������:
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) ������ �������� ������ ������� �������: 
		int* buffer = new int[cols + 1] {};
		//2) �������� �������� �� �������� ������ � ��������:
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) ������� �������� ������:
		delete[] arr[i];
		//4) ��������� ����� �������� ������ ������� ����� ������:
		arr[i] = buffer;
	}
	cols++;
}