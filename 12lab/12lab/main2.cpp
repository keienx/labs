//#include "Pair.h"
//#include <iostream>
//#include <set>
//using namespace std;
//typedef multiset<Pair> TMS;
//typedef TMS::iterator it;
//
//TMS make_set(int n) {
//	srand(time(NULL));
//	TMS ms;
//	for (int i = 0; i < n; i++) {
//		Pair a(rand() % 20, round(((double)(rand()) / RAND_MAX * 10 + 1) * 100) / 100);
//		ms.insert(a);
//	}
//	return ms;
//}
//
//void print_TMS(TMS m) {
//	int k = 1;
//	for (it i = m.begin(); i != m.end(); i++) cout << k++ << ") " << *i;
//}
//
//Pair srednee(TMS& ms) {
//	Pair s;
//	for (it i = ms.begin(); i != ms.end(); ++i) s += *i;
//	int n = ms.size();
//	s = s / n;
//	return s;
//}
//void add_TMS(TMS& ms, Pair el) {
//	ms.insert(el);
//}
//
//void remove_elements(TMS& ms, Pair rmin, Pair rmax) {
//	if (rmin > rmax) swap(rmin, rmax);
//	for (it i = ms.begin(); i != ms.end();) {
//		if (*i <= rmax && *i >= rmin)
//			i = ms.erase(i);
//		else
//			++i;
//	}
//}
//
//Pair max(TMS& ms) {
//	it i = ms.end();
//	--i;
//	Pair max = *i;
//	return max;
//}
//
//Pair min(TMS& ms) {
//	it i = ms.begin();
//	Pair min = *i;
//	return min;
//}
//
//void increase_elements(TMS& ms, Pair min, Pair max) {
//	TMS m1;
//	for (it i = ms.begin(); i != ms.end(); ++i) {
//		Pair temp = min + max + *i;
//		m1.insert(temp);
//	}
//	ms = m1;
//}
//
//int main() {
//	system("color F0");
//	system("chcp 1251 >> null");
//	int size;
//	Pair range_min, range_max, min_el, max_el;
//	cout << "Размер?= "; 
//	cin >> size;
//	TMS ms = make_set(size);
//	print_TMS(ms);
//	Pair el = srednee(ms);
//	add_TMS(ms, el);
//	cout << "Добавление среднего арифметического\n";
//	print_TMS(ms);
//	cout << "Установите промежуток удаляемых элементов:\nОт:\n"; 
//	cin >> range_min;
//	cout << "До:\n"; 
//	cin >> range_max;
//	cout << "Удаление элементов:\n";
//	remove_elements(ms, range_min, range_max);
//	print_TMS(ms);	
//	min_el = min(ms);
//	max_el = max(ms);
//	cout << "Добавление к элементам максимального и минимального значения:\n";
//	increase_elements(ms, min_el, max_el);
//	print_TMS(ms);
//	return 0;
//}