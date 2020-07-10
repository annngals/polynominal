#pragma once
#include <iostream>
using namespace std;

class Poly
{
	setlocale(LC_ALL, "rus");
	
	friend ostream &operator<<(ostream &, const Poly &);	//peregruzka operatora vivoda

private:
	static const int volume = 100;	//opredelenie peremennoi znacheniya
	int degree;		//opredelenie peremennoi stepeni
	int* num;

public:
	Poly();		//konstructori
	Poly(int *, const int);
	Poly(Poly &);
	Poly &operator+(const Poly &);	//peregruzka operatora slozheniya
	Poly &operator-(const Poly &);	//peregruzka operatora vichitaniya

	bool operator>(const Poly &) const; //peregruzka operatora sravneniya

	double Solve(double) const;		//funktsiya resheniya mnogochlena
	double Check(double, double);		//funktsiya proverki reseniya na intervale
	double Integrate(double, double) const;		//funktsiya integratsii
	void Derivate();	//funktsiya nahozhdeniya proizvodnoi
};
