#pragma once
#include <iostream>
using namespace std;

class Poly
{
	friend ostream &operator<<(ostream &, const Poly &);	//���������� ��������� ������

private:
	static const int volume = 100;	//����������� ���������� ��������
	int degree;		//����������� ���������� �������
	int* num;

public:
	Poly();		//������������
	Poly(int *, const int);
	Poly(Poly &);
	Poly &operator+(const Poly &);	//���������� ��������� ��������
	Poly &operator-(const Poly &);	//���������� ��������� ���������

	bool operator>(const Poly &) const; //���������� ��������� ���������

	double Solve(double) const;		//������� ������� ����������
	double Integrate(double, double) const;		//������� ����������
	void Derivate();	//������� ���������� �����������
};