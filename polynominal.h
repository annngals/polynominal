#pragma once
#include <iostream>
using namespace std;

class Poly
{
	friend ostream &operator<<(ostream &, const Poly &);	//перегрузка оператора вывода

private:
	static const int volume = 100;	//определение переменной значения
	int degree;		//определение переменной степени
	int* num;

public:
	Poly();		//конструкторы
	Poly(int *, const int);
	Poly(Poly &);
	Poly &operator+(const Poly &);	//перегрузка оператора сложения
	Poly &operator-(const Poly &);	//перегрузка оператора вычитания

	bool operator>(const Poly &) const; //перегрузка оператора сравнения

	double Solve(double) const;		//функция решения многочлена
	double Integrate(double, double) const;		//функция интеграции
	void Derivate();	//функция нахождения производной
};