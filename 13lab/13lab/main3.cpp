#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include "Pair.h"
using namespace std;

ostream& operator<<(ostream& out, map<double, Pair>& m) {
	for (map <double, Pair>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "Сумма - " << it->first << ", Значение - " << it->second;
	}
	return out;
}

void print_vect(Pair elem) {
	cout << "Сумма - " << elem.sum() << ", Значение - " << elem << "\n";
}

void menu(const int c, map<double, Pair>& m) {
	switch (c) {
	case 1: {
		cout << m << "\n";
		cout << "Введите B для сортировки по возрастанию \nВведите U для сортировки по убыванию\n";
		char op;
		cin >> op;
		if (op == 'B') {
			cout << m << "\n";
		}
		else if (op == 'U') {
			vector<Pair> v;
			Pair elem;
			for (map <double, Pair>::iterator it = m.begin(); it != m.end(); ++it) {
				elem = it->second;
				v.push_back(elem);
			}
			sort(v.begin(), v.end(), mem_fun_ref(&Pair::operator>));
			for_each(v.begin(), v.end(), ptr_fun(print_vect));
			v.~vector();
		}
		else {
			cout << "Ошибка ввода!\n";
		}

		break;
	}
	case 2: {
		cout << m << "\n\n";
		cout << "Значение?\n";
		Pair value;
		cin >> value;
		const auto it = find_if(m.begin(), m.end(), [&value](decltype(*m.begin())& it)->bool {
			return it.second == value;
			});

		if (it == m.end()) {
			cout << "Нет такого элемента" << "\n";
			break;
		}
		for (map<double, Pair>::iterator i = m.begin(); i != m.end(); ++i) {
			if (i == it) {
				cout << "Элемент -  " << i->second << "\n";
			}
		}
		break;
	}
	case 3: {
		cout << m << "\n" << "\n";
		Pair sum;
		for (auto it = m.begin(); it != m.end(); it++) sum += it->second;
		sum.set_first(sum.get_first() / m.size());
		sum.set_second(round((double)(sum.get_second() / m.size()) * 100) / 100);
		cout << "Среднее арифметическое - " << sum.sum() << " По элементам - " << sum << "\n\n";
		m.insert(make_pair(sum.sum(), sum));
		cout << m << "\n";
		break;
	}
	case 4: {
		cout << m << "\n" << "\n";
		int one, two;
		cout << "\nПервая граница?\n"; cin >> one;
		cout << "\nВторая граница?\n"; cin >> two;
		if (one > two) swap(one, two);
		while (find_if(m.begin(), m.end(), [&one, &two](decltype(*m.begin())& it) -> bool {
			return it.second.sum() > one && it.second.sum() < two; 
			}) != m.end()) {
			const auto it = find_if(m.begin(), m.end(), [&one, &two](decltype(*m.begin())& it) -> bool {
				return it.second.sum() > one && it.second.sum() < two;
				});
			m.erase(it->first);
		}

		cout << "\n" << m << "\n";
		break;
	}
	case 5: {
		cout << m << "\n" << "\n";
		const auto mini = m.begin();
		const auto maxi = --m.end();
		cout << "Минимальное: " << mini->second << "\n";
		cout << "Максимальное: " << maxi->second << "\n";

		Pair sum;
		sum = mini->second + maxi->second;
		cout << "Сумма = " << sum << "\n";
		for (auto it = m.begin(); it != m.end(); it++) {
			it->second.set_second(it->second.get_second() + sum.get_second());
			it->second.set_first(it->second.get_first() + sum.get_first());
		}
		cout << "\n" << m << "\n";
		break;
	}
	case 6: {
		cout << m << "\n";
		break;
	}
	default: {
		cout << "\nВыход в меню" << "\n";
		exit(0);
	}
	}
}


int main() {
	srand(time(NULL));
	system("color F0");
	system("chcp 1251 >> null");
	int size;
	cout << "Размер? ";
	cin >> size;
	map<double, Pair> m;
	for (int i = 0; i < size; ++i) {
		Pair p;
		p.set_random();
		m.insert(make_pair(p.sum(), p));
	}
	cout << m << "\n";

	while (true) {
		system("pause");
		system("cls");
		cout << "1. Отсортировать\n";
		cout << "2. Найти пару\n";
		cout << "3. Добавить среднее арифметическое\n";
		cout << "4. Удалить элементы из диапазона\n";
		cout << "5. Добавить минимальное и максимальное значение\n";
		cout << "6. Вывод на экран\n";
		cout << "0. Завершение работы программы\n";
		int c;
		cin >> c;
		system("cls");
		menu(c, m);
	}
	return 0;
}