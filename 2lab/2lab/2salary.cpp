#include "Header.h"
#include <iostream>
#include <string>
using namespace std;
//����������� ��� ����������
salary::salary()
{
	name = "NULL";
	money = 0;
	premium = 0;
	cout << "����������� ��� ���������� ��� ������� " << this << endl;
}
//����������� � �����������
salary::salary(string N, int M, int P)
{
	name = N;
	money = M;
	premium = M / 100 * P;
	cout << "����������� � ����������� ��� ������� " << this << endl;
}
//����������� �����������
salary::salary(const salary& t)
{
	name = t.name;
	money = t.money;
	premium = t.premium;
	cout << "����������� ����������� ��� ������� " << this << endl;
}
//����������
salary::~salary()
{
	cout << "���������� ��� ������� " << this << endl;
}
//���������
string salary::get_name()
{
	return name;
}
int salary::get_money()
{
	return money;
}
int salary::get_premium()
{
	return premium;
}
//������������
void salary::set_name(string N)
{
	name = N;
}
void salary::set_money(int M)
{
	money = M;
}
void salary::set_premium(int M, int P)
{
	premium = M / 100 * P;
}
//����� ��� ��������� ���������
void salary::show()
{
	cout << "name :" << name << endl;
	cout << "money :" << money << endl;
	cout << "premium :" << premium << endl;
}
