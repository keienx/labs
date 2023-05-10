#include "student.h"

Student::Student(void) :Person() {
	subject = "";
	mark = 0;
}
Student::~Student(void) {}

Student::Student(string N, int A, string S, int M) :Person(N, A) {
	subject = S;
	mark = M;
}

Student::Student(const Student& S) {
	name = S.name;
	age = S.age;
	subject = S.subject;
	mark = S.mark;
}

Student& Student::operator =(const Student& S) {
	if (&S == this) return *this;
	name = S.name;
	age = S.age;
	subject = S.subject;
	mark = S.mark;
	return *this;
}

ostream& operator<<(ostream& out, const Student& S) {
	out << "Имя: " << S.name;
	out << "\nВозраст: " << S.age;
	out << "\nПредмет: " << S.subject;
	out << "\nОценка: " << S.mark;
	out << "\n\n";
	return out;
}

istream& operator>>(istream& in, Student& S) {
	cout << "Имя?: ";
	in >> S.name;
	cout << "Возраст?: ";
	in >> S.age;
	cout << "Предмет?: ";
	in >> S.subject;
	cout << "Оценка?: ";
	in >> S.mark;
	cout << "\n";
	return in;
}

void Student::markCheck() {
	if (mark <= 2) {
		cout << "Оценка неудовлетворительна\n";
	}
	else {
		if (mark > 2) {
			cout << "Оценка удовлетворительна\n";
		}
	}
}
void Student::show() {
	cout << "\nИмя:" << name;
	cout << "\nВозраст:" << age;
	cout << "\nПредмет:" << subject;
	cout << "\nОценка:" << mark;
	cout << "\n";
}