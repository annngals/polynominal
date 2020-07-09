#pragma once
#include <iostream>
#include <locale.h>
#include "main.cpp"
using namespace std;

class Poly
{
	setlocale(LC_ALL, "rus");
	
	friend ostream &operator<<(ostream &, const Poly &);	//ïåðåãðóçêà îïåðàòîðà âûâîäà

private:
	static const int volume = 100;	//îïðåäåëåíèå ïåðåìåííîé çíà÷åíèÿ
	int degree;		//îïðåäåëåíèå ïåðåìåííîé ñòåïåíè
	int* num;

public:
	Poly();		//êîíñòðóêòîðû
	Poly(int *, const int);
	Poly(Poly &);
	Poly &operator+(const Poly &);	//ïåðåãðóçêà îïåðàòîðà ñëîæåíèÿ
	Poly &operator-(const Poly &);	//ïåðåãðóçêà îïåðàòîðà âû÷èòàíèÿ

	bool operator>(const Poly &) const; //ïåðåãðóçêà îïåðàòîðà ñðàâíåíèÿ

	double Solve(double) const;		//ôóíêöèÿ ðåøåíèÿ ìíîãî÷ëåíà
	double Integrate(double, double) const;		//ôóíêöèÿ èíòåãðàöèè
	void Derivate();	//ôóíêöèÿ íàõîæäåíèÿ ïðîèçâîäíîé
};
