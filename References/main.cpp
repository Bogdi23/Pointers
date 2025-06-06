#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int a = 2;
	int& ra = a; // Компилятор сам, неявно берёт адрес переменной 'a', и записывает его в ссылку 'ra'
	ra += 3;
	cout << a << endl;
}