//#include <iostream>
//#include <list>
//#include <algorithm>
//#include <functional>
//#include "Pair.h"
//using namespace std;
//
//ostream& operator<<(ostream& out, list<Pair>& l) {
//	for_each(l.begin(), l.end(), [](Pair& p) {
//		cout << p; 
//		}
//	);
//	return out;
//}
//
//bool EQUAL(Pair a, Pair t) {
//	if (a == t) {
//		return true;
//	}
//	return false;
//}
//
//void menu(const int c, list<Pair>& l) {
//	switch (c) {
//
//	case 1: {
//		cout << l << "\n";
//		cout << "Введите B для сортировки по возрастанию \nВведите U для сортировки по убыванию\n";
//		char op;
//		cin >> op;
//		if (op == 'B') {
//			l.sort(mem_fun_ref(&Pair::operator<));
//		}
//		else if (op == 'U') {
//			l.sort(mem_fun_ref(&Pair::operator>));
//		}
//		else {
//			cout << "Ошибка ввода!\n";
//		}
//		cout << l << "\n";
//		break;
//	}
//
//	case 2: {
//		cout << l << "\n\n";
//		cout << "Введите значение:\n";
//		Pair value;
//		cin >> value;
//		auto it = find_if(l.begin(), l.end(), bind2nd(ptr_fun(EQUAL), value));
//		if (it == l.end()) {
//			cout << "Нет такого элемента!" << "\n";
//			break;
//		}
//		for (list<Pair>::iterator i = l.begin(); i != l.end(); ++i) {
//			if (i == it) {
//				cout << "Элемент -  " << *i << "\n";
//			}
//		}
//		break;
//	}
//
//	case 3: {
//		cout << l << "\n" << "\n";
//		Pair sum;
//		for_each(l.begin(), l.end(), [&sum](Pair& p) {sum += p; });
//		sum.set_first(sum.get_first() / l.size());
//		sum.set_second(sum.get_second() / l.size());
//		l.push_back(sum);
//		cout << l << "\n";
//		break;
//	}
//
//	case 4: {
//		cout << l << "\n";
//		Pair one, two;
//		cout << "Сумма каждой пары: " << "\n";
//		for_each(l.begin(), l.end(), [](Pair& p) {cout << p.sum() << ' '; });
//
//		cout << "\nПервая граница?\n"; cin >> one;
//		cout << "\nВторая граница?\n"; cin >> two;
//		if (one > two) {
//			swap(one, two);
//		}
//
//		auto s = remove_if(l.begin(), l.end(), [one, two](Pair& p) {return p >= one && p <= two; });
//		l.erase(s, l.end());
//
//		cout << "Элементы после удаления: " << "\n";
//		for_each(l.begin(), l.end(), [](Pair& p) {cout << p; });
//		break;
//	}
//
//	case 5: {
//		cout << l << "\n" << "\n";
//		auto mini = min_element(l.begin(), l.end());
//		auto maxi = max_element(l.begin(), l.end());
//		cout << "Минимальное: " << *mini;
//		cout << "Максимальное: " << *maxi;
//		Pair sum;
//		sum = *mini + *maxi;
//		cout << "Сумма = " << sum << "\n";
//		for_each(l.begin(), l.end(), [&sum](Pair& p) {p += sum; });
//		cout << "\n" << l << "\n";
//		break;
//	}
//
//	case 6: {
//		cout << l << "\n";
//		break;
//	}
//
//	default: {
//		cout << "\nЗавершение работы" << "\n";
//		exit(0);
//	}
//	}
//}
//
//
//int main() {
//	system("color F0");
//	system("chcp 1251 >> null");
//	srand(time(NULL));
//	int size;
//	cout << "Размер? ";
//	cin >> size;
//	list<Pair> l(size);
//	generate(l.begin(), l.end(), []() {Pair p; p.set_random(); return p; });
//	cout << l << "\n";
//	while (true) {
//		system("pause");
//		system("cls");
//		cout << "1. Отсортировать\n";
//		cout << "2. Найти пару\n";
//		cout << "3. Добавить среднее арифметическое\n";
//		cout << "4. Удалить элементы из диапазона\n";
//		cout << "5. Добавить минимальное и максимальное значение\n";
//		cout << "6. Вывод на экран\n";
//		cout << "0. Завершение работы программы\n";
//		int c;
//		cin >> c;
//		system("cls");
//		menu(c, l);
//	}
//	return 0;
//}