#include <C:\Users\Admin\Desktop\vsc\�� ��\12lab\12lab\pair.h>
#include <iostream>
#include <set>
#include "List.h"
using namespace std;

int main() {
	system("color F0");

	system("chcp 1251 >> null");
	int size;
	cout << "������? ";
	cin >> size;
	List<Pair> l(size);
	l.Print();
	Pair range_min, range_max, min_el, max_el;
	Pair el = l.srednee();
	l.add_list(el);
	cout << "���������� �������� ���������������\n";
	l.Print();
	cout << "���������� ���������� ��������� ���������:\n��:\n"; 
	cin >> range_min;
	cout << "to:\n"; 
	cin >> range_max;
	cout << "�������� ���������:\n";
	l.remove_elements(range_min, range_max);
	l.Print();
	min_el = l.min();
	max_el = l.max();
	cout << "���������� � ��������� ������������� � ������������ ��������:\n";
	l.increase_elements(min_el, max_el);
	l.Print();
	return 0;
}