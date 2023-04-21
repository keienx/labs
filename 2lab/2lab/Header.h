#pragma once
#include <iostream>
#include <string>

using namespace std;

class salary{
	string name;
	int money;
	int premium;
public:
	salary();//конструктор без параметров
	salary(string, int, int);//конструктор с параметрами
	salary(const salary&);//конструктор копирования
	~salary();//деструктор
	string get_name();//селектор
	void set_name(string);//модификатор
	int get_money();//селектор
	void set_money(int); //модификатор
	int get_premium();//селектор
	void set_premium(int, int); //модификатор
	void show();//просмотр атрибутов
};