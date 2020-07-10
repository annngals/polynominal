#include "pch.h"
#include <math.h>
#include "polynominal.h"

Poly::Poly()	//конструктор по умолчанию
{
	num = new int[volume];
	for (int i = 0; i < volume; i++)
		num[i] = 0;
	degree = 0;
}

Poly::Poly(Poly &m) //конструктор по ссылке
{
	num = new int[volume];
	for (int i = 0; i < volume; i++)
		num[i] = m.num[i];
	degree = m.degree;
}

Poly::Poly(int *arr, const int m)	//конструктор с условиями
{
	num = new int[volume];
	for (int i = 0; i < volume; i++)
		num[i] = arr[i];
	degree = m;
}

ostream &operator<<(ostream &out, const Poly &P)	//оператор вывода
{
	for (int i = P.degree - 1; i >= 0; i--)
	{
		if (P.num[i] >= 0)
		{
			out << "+";
		}
		else
		{
			out << "-";
		}
		out << abs(P.num[i]) << "^x" << i << " ";
	}
	return out;
}

bool Poly::operator>(const Poly &P) const	//оператор сравнения
{
	return degree > P.degree;
}

Poly &Poly::operator+(const Poly &P) //оператор сложения
{
	if (degree < P.degree)
	{
		for (int i = degree; i < P.degree; i++)
			num[i] = 0;
		degree = P.degree;
		for (int i = 0; i < degree; i++)
			num[i] += P.num[i];
	}
	else
		for (int i = 0; i < P.degree; i++)
			num[i] += P.num[i];
	return *this;
}

Poly &Poly::operator-(const Poly &P)	//оператор вычитания
{
	if (degree < P.degree)
	{
		for (int i = degree; i < P.degree; i++)
			num[i] = 0;
		degree = P.degree;
		for (int i = 0; i < degree; i++)
			num[i] += P.num[i];
	}
	else
		for (int i = 0; i < P.degree; i++) {
			num[i] -= 2*P.num[i];
		}
	return *this;
}

double Poly::Solve(double x)	//решение по заданному аргументу
{
	double d = 0;
	for (int i = 0; i < degree; i++)
	{
		d += num[i] * pow(x, i);
	}
	solve = d;
	return d;
}

double Poly::Check(double a, double b)	//проверка решения на интервале
{
	int p = 0;
	for (double j = a; j <= b; j+=0.001)
	{
		for (int i = 0; i < degree; i++)
		{
			p += (double)num[i] * pow(j, i);
		}
		if (p == 0) {
			break;
		}
	}
	if (p == 0) {
		cout << "Interval check: yes" << endl;
	}
	else {
		cout << "Interval check: no" << endl;
	}
	return p;
}

double Poly::Integrate(double a, double b) const	//интегрирование
{
	double j = 0;
	for (int i = 0; i < degree; i++)
		j += ((double)num[i] / (double)(i + 1)) * (pow(b, (i + 1)) - pow(a, (i + 1)));
	return j;
}

void Poly::Derivate()	//нахождение производной
{
	num[degree] = 0;
	for (int i = 0; i < degree; i++)
	{
		num[i] = num[i + 1] * (i + 1);
	}
	degree--;
}
