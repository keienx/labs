#include "Header.h"
#include <iostream>
#include <string>
using namespace std;
//������� ��� �������� ������� ��� ����������
//������� ��� �������� ������� ��� ���������
void print_salary(salary t)
{
	t.show();
}
int main()
{
	system("chcp 1251 >> null");
	//����������� ��� ����������
	salary t1;
	t1.show();
	//���������� � �����������
	salary t2("�������", 100000, 10);
	t2.show();
	//����������� �����������
	salary t3 = t2;
	/*t3.set_name("������");
	t3.set_money(200000);
	t3.set_premium(200000, 20);*/
	//����������� �����������
	print_salary(t3);
	//����������� �����������
}