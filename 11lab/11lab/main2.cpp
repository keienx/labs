//#include "pair.h"
//#include <iostream>
//#include <list> 
//#include <cstdlib> 
//using namespace std;
//typedef list<Pair>List;
//
//List make_list(int n) {
//	List l;
//	for (int i = 0; i < n; ++i) {
//		Pair a;
//		cin >> a;
//		l.push_back(a);
//	}
//	return l;
//}
//
//void print_list(List& l) {
//	for (auto it = l.begin(); it != l.end(); ++it)
//		cout << *it;
//	cout << "\n";
//}
//
//Pair srednee(List& l) {
//	Pair s;
//	for (auto it = l.begin(); it != l.end(); ++it) s += *it;
//	int n = l.size();
//	s = s / n;
//	return s;
//}
//
//void add_list(List& l, Pair el) {
//	l.insert(l.end(), el);
//}
//
//void remove_elements(List& l, Pair rmin, Pair rmax) {
//	if (rmax < rmin) swap(rmin, rmax);
//	for (auto it = l.begin(); it != l.end();) {
//		if (*it <= rmax && *it >= rmin)
//			it = l.erase(it);
//		else
//			++it;
//	}
//}
//
//Pair max(List& l) {
//	Pair max(INT_MIN, INT_MIN);
//	for (auto it = l.begin(); it != l.end(); ++it)
//		if (*it > max)
//			max = *it;
//	return max;
//}
//
//Pair min(List& l) {
//	Pair min(INT_MAX, INT_MAX);
//	for (auto it = l.begin(); it != l.end(); ++it)
//		if (*it < min)
//			min = *it;
//	return min;
//}
//
//void increase_elements(List& l, Pair min, Pair max) {
//	for (auto it = l.begin(); it != l.end(); ++it)
//		*it = *it + min + max;
//}
//
//int main() {
//	system("color F0");
//	system("chcp 1251 >> null");
//	try {
//		list<Pair> l;
//		int size;
//		Pair range_min, range_max, min_el, max_el;
//		cout << "Размер? "; 
//		cin >> size;
//		l = make_list(size);
//		print_list(l);
//		Pair el = srednee(l);
//		add_list(l, el);
//		cout << "Добавление среднего арифметического\n";
//		print_list(l);
//		cout << "Установите промежуток удаляемых элементов:\nОт: ";
//		cin >> range_min;
//		cout << "До: ";
//		cin >> range_max;
//		cout << "Удаление элементов:\n";
//		remove_elements(l, range_min, range_max);
//		print_list(l);
//		min_el = min(l);
//		max_el = max(l);
//		cout << "Добавление к элементам максимального и минимального значения:\n";
//		increase_elements(l, min_el, max_el);
//		print_list(l);
//	}
//	catch (int) {
//		cout << "Ошибка!";
//	}
//	return 0;
//}
