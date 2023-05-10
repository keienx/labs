//#include <iostream>
//#include <set>
//using namespace std;
//typedef multiset<double> TMS;
//typedef TMS::iterator it;
//
//TMS make_set(int n) {
//	srand(time(NULL));
//	TMS s;
//	double a;
//	for (int i = 0; i < n; i++) {
//		a = round(((double)(rand()) / RAND_MAX * 10 + 1) * 100) / 100;
//		s.insert(a);
//	}
//	return s;
//}
//
//void print_TMS(TMS m) {
//	int k = 1;
//	for (it i = m.begin(); i != m.end(); i++) {
//		cout << k++ << " : " << *i << " " << endl;
//	}
//}
//
//double srednee(TMS& ms) {
//	double s = 0;
//	for (it i = ms.begin(); i != ms.end(); ++i) {
//		s += *i;
//	}
//	int n = ms.size();
//	return s / n;
//}
//void add_TMS(TMS& ms, double el) {
//	ms.insert(el);
//}
//
//void remove_elements(TMS& ms, double rmin, double rmax) {
//	if (rmin > rmax) {
//		swap(rmin, rmax);
//		for (it i = ms.begin(); i != ms.end();) {
//			if (*i <= rmax && *i >= rmin) {
//				i = ms.erase(i);
//			}
//			else {
//				++i;
//			}
//		}
//	}
//}
//
//double max(TMS& ms) {
//	it i = ms.end();
//	--i;
//	double max = *i;
//	return max;
//}
//
//double min(TMS& ms) {
//	it i = ms.begin();
//	double min = *i;
//	return min;
//}
//
//void increase_elements(TMS& ms, double min, double max) {
//	TMS m1;
//	for (it i = ms.begin(); i != ms.end(); ++i) {
//		double temp = *i + min + max;
//		m1.insert(temp);
//	}
//	ms = m1;
//}
//
//int main() {
//	system("color F0");
//	system("chcp 1251 >> null");
//	int size;
//	double range_min, range_max, min_el, max_el;
//	cout << "Размер? = "; 
//	cin >> size;
//	TMS ms = make_set(size);
//	print_TMS(ms);
//	double el = srednee(ms);
//	add_TMS(ms, el);
//	cout << "Добавление среднего арифметического\n";
//	print_TMS(ms);
//	cout << "Установите промежуток удаляемых элементов:\nОт:\n"; 
//	cin >> range_min;
//	cout << "До: "; 
//	cin >> range_max;
//	cout << "Удаление элементов:\n";
//	remove_elements(ms, range_min, range_max);
//	print_TMS(ms);
//	min_el = min(ms);
//	max_el = max(ms);
//	cout << "\nДобавление к элементам максимального и минимального значения:\n";
//	increase_elements(ms, min_el, max_el);
//	print_TMS(ms);
//	return 0;
//}