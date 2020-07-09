#include "pch.h"
#include "polynominal.h"
#include <iostream>

using namespace std;

int main()
{
	int coff1[] = { 4,5,2,7 };		//���� �������� ��� ������� ���������� �1
	int coff2[] = { 3,6,2 };		//���� �������� ��� ������� ���������� �2

	Poly poly1(coff1, 4);		//����������� ���������� �1
	cout << "poly 1: " << poly1 << endl;

	Poly poly2(coff2, 3);		// ����������� ���������� �2
	cout << "poly 2: " << poly2 << endl;
	
	cout << "Solve poly1: " << poly1.Solve(2) << endl;	//����� ������� ���������� �1 �� ��������� ��������� = 2
	cout << "Solve poly2: " << poly2.Solve(2) << endl;	//����� ������� ���������� �2 �� ��������� ��������� = 2
	cout << "Sum: " << poly1 + poly2 << endl;	//����� ����� �����������
	cout << "Diff: " << poly1 - poly2 << endl;	//����� �������� �����������
	cout << "Integrate poly2: " << poly1.Integrate(0, 1) << endl;		//����� ��������� ���������� �2

	poly2.Derivate();
	cout << "Derivate poly2: " << poly2 << endl;		//����� ����������� ���������� �1

	return 0;
}