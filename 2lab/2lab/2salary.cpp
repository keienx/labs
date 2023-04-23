#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

//конструктор без параметров

salary::salary(){
	name = "NULL";
	money = 0;
	premium = 0;
	cout << "Конструктор без параметров для объекта " << this << '\n';
}

//конструктор с параметрами

salary::salary(string N, int M, int P){
	name = N;
	money = M;
	premium = M / 100 * P;
	cout << "Конструктор с параметрами для объекта " << this << '\n';
}
//конструктор копирования

salary::salary(const salary& t){
	name = t.name;
	money = t.money;
	premium = t.premium;
	cout << "Конструктор копирования для объекта " << this << '\n';
}

//деструктор

salary::~salary(){
	cout << "Деструктор для объекта " << this << '\n';
}

//селекторы

string salary::get_name(){
	return name;
}

int salary::get_money(){
	return money;
}

int salary::get_premium(){
	return premium;
}

//модификаторы

void salary::set_name(string N){
	name = N;
}

void salary::set_money(int M){
	money = M;
}

void salary::set_premium(int M, int P){
	premium = M / 100 * P;
}

//метод для просмотра атрибутов

void salary::show(){
	cout << "name :" << name << '\n';
	cout << "money :" << money << '\n';
	cout << "premium :" << premium << '\n';
}
