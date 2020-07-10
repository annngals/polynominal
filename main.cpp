#include "pch.h"
#include "polynominal.h"
#include <iostream>
#include <locale.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int coff1[] = { 2,3,4,3 };		//ввод значений для массива многочлена №1
	int coff2[] = { 3,6,2 };		//ввод значений для массива многочлена №2

	Poly poly1(coff1, 4);		//определение многочлена №1
	cout << "poly 1: " << poly1 << endl;

	Poly poly2(coff2, 3);		// определение многочлена №2
	cout << "poly 2: " << poly2 << endl;
	
	cout << "Solve poly1: " << poly1.Solve(2) << endl;	//вывод решения многочлена №1 со значением аргумента = 2
	cout << "Solve poly2: " << poly2.Solve(2) << endl;	//вывод решения многочлена №2 со значением аргумента = 2
	cout << "Check poly2: " << poly1.Check(-1.0, 2.0) << endl;	//проверка решения на интервале
	cout << "Sum: " << poly1 + poly2 << endl;	//вывод суммы многочленов
	cout << "Diff: " << poly1 - poly2 << endl;	//вывод разности многочленов
	cout << "Integrate poly2: " << poly1.Integrate(0, 1) << endl;		//вывод интеграла многочлена №2

	poly2.Derivate();
	cout << "Derivate poly2: " << poly2 << endl;		//вывод производной многочлена №1

	return 0;
}
