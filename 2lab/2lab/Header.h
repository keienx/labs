#pragma once
#include <iostream>
#include <string>

using namespace std;

class salary{
	string name;
	int money;
	int premium;
public:
	salary();//����������� ��� ����������
	salary(string, int, int);//����������� � �����������
	salary(const salary&);//����������� �����������
	~salary();//����������
	string get_name();//��������
	void set_name(string);//�����������
	int get_money();//��������
	void set_money(int); //�����������
	int get_premium();//��������
	void set_premium(int, int); //�����������
	void show();//�������� ���������
};