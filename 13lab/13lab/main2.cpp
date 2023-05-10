//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//#include <functional>
//#include "Pair.h"
//using namespace std;
//
//ostream& operator<<(ostream& out, priority_queue<Pair>& q) {
//	vector<Pair> v;
//	Pair elem;
//	int num = q.size();
//	for (size_t i = 0; i < num; ++i) {
//		elem = q.top();
//		cout << elem;
//		v.push_back(elem);
//		q.pop();
//	}
//	int k = 0;
//	for (int i = 0; i < v.size(); ++i) {
//		q.push(v[k++]);
//	}
//	v.clear();
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
//void menu(const int c, priority_queue<Pair>& q) {
//	switch (c) {
//	case 1: {
//		char op;
//		cout << "Введите B для сортировки по возрастанию \nВведите U для сортировки по убыванию\n";
//		cin >> op;
//		if (op == 'U') {
//			cout << q << "\n";
//		}
//		else if (op == 'B') {
//			vector<Pair> v;
//			Pair elem;
//			int num = q.size();
//			for (int i = 0; i < num; ++i) {
//				elem = q.top();
//				v.push_back(elem);
//				q.pop();
//			}
//			sort(v.begin(), v.end(), mem_fun_ref(&Pair::operator<));
//			for_each(v.begin(), v.end(), [](Pair& p) {cout << p; });
//			while (!v.empty()) {
//				q.push(v[v.size() - 1]);
//				v.pop_back();
//			}
//		}
//		else{
//			cout << "Ошибка ввода!\n";
//		}
//		break;
//	}
//
//	case 2: {
//		cout << q << "\n\n";
//		cout << "Введите значение:\n";
//		Pair value;
//		cin >> value;
//		auto f = [value](priority_queue<Pair>& q) {
//			vector<Pair> v;
//			Pair elem;
//			bool flag = false;
//			int num = q.size();
//			for (int i = 0; i < num && !flag; ++i) {
//				elem = q.top();
//				if (EQUAL(elem, value)) {
//					flag = true;
//					cout << "Элемент -  " << elem << "\n";
//				}
//				v.emplace_back(elem);
//				q.pop();
//			}
//			if (!flag) cout << "Нет такого элемента\n";
//			while (!v.empty()) {
//				q.push(v[v.size() - 1]);
//				v.pop_back();
//			}
//		};
//		f(q);
//		break;
//	}
//
//	case 3: {
//		cout << q << "\n";
//		vector<Pair> v;
//		Pair elem;
//		while (!q.empty()) {
//			elem = q.top();
//			v.push_back(elem);
//			q.pop();
//		}
//		Pair sum;
//		for_each(v.begin(), v.end(), [&sum](Pair& p) {sum += p; });
//		sum.set_first(round(sum.get_first() / v.size() * 100) / 100);
//		sum.set_second(round(sum.get_second() / v.size() * 100) / 100);
//		cout << "Среднее арифметическое -  " << sum << "\n\n";
//		q.push(sum);
//		while (!v.empty()) {
//			q.push(v[v.size() - 1]);
//			v.pop_back();
//		}
//		cout << q << "\n";
//		break;
//	}
//
//	case 4: {
//		cout << q << "\n";
//		Pair elem;
//		vector<Pair> v;
//		while (!q.empty()) {
//			elem = q.top();
//			v.push_back(elem);
//			q.pop();
//		}
//		Pair one, two;
//		cout << "Сумма каждой пары: " << "\n";
//		for_each(v.begin(), v.end(), [](Pair& p) {cout << p.sum() << " "; });
//
//		cout << "\nПервая граница?\n"; cin >> one;
//		cout << "\nВторая граница?\n"; cin >> two;
//		if (one > two) swap(one, two);
//
//		auto s = remove_if(v.begin(), v.end(), [one, two](Pair& p) {return p >= one && p <= two; });
//		v.erase(s, v.end());
//
//		while (!v.empty()) {
//			q.push(v[v.size() - 1]);
//			v.pop_back();
//		}
//		cout << "\n" << q << "\n";
//		break;
//	}
//
//	case 5: {
//		cout << q << "\n" << "\n";
//		Pair elem;
//		vector<Pair> v;
//		while (!q.empty()) {
//			elem = q.top();
//			v.push_back(elem);
//			q.pop();
//		}
//		auto mini = v[v.size() - 1];
//		auto maxi = v[0];
//		cout << "Минимальное: " << mini;
//		cout << "Максимальное: " << maxi;
//		Pair sum;
//		sum = mini + maxi;
//		cout << "Сумма = " << sum << "\n";
//		for_each(v.begin(), v.end(), [&sum](Pair& p) {p += sum; });
//		while (!v.empty()) {
//			q.push(v[v.size() - 1]);
//			v.pop_back();
//		}
//		cout << "\n" << q << "\n";
//		break;
//	}
//
//	case 6: {
//		cout << q << "\n";
//		break;
//	}
//
//	default: {
//		cout << "\nВыход в меню" << "\n";
//		exit(0);
//	}
//	}
//}
//
//int main() {
//	srand(time(NULL));
//	system("color F0");
//	system("chcp 1251 >> null");
//	int size;
//	cout << "Размер очереди? ";
//	cin >> size;
//	priority_queue<Pair> q;
//	Pair p;
//	for (int i = 0; i < size; ++i) {
//		p.set_random();
//		q.push(p);
//	}
//
//	cout << q << "\n";
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
//		menu(c, q);
//	}
//	return 0;
//}
