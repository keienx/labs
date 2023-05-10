#include "student.h"

void f1(Person& c) {
	c.set_age(99);
	cout << c;
}

Person f2() {
	Student s("Александр", 10, "алгебра", 4);
	return s;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person a;
	cin >> a;
	cout << a;

	Person b("Гарик", 5);
	a = b;
	cout << a;

	Student c;
	cin >> c;
	cout << c;
	f1(c);
	a = f2();
	cout << a;
	cout << c;
	c.markCheck();
	return 0;
}
