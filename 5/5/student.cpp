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
	out << "���: " << S.name;
	out << "\n�������: " << S.age;
	out << "\n�������: " << S.subject;
	out << "\n������: " << S.mark;
	out << "\n\n";
	return out;
}

istream& operator>>(istream& in, Student& S) {
	cout << "���?: ";
	in >> S.name;
	cout << "�������?: ";
	in >> S.age;
	cout << "�������?: ";
	in >> S.subject;
	cout << "������?: ";
	in >> S.mark;
	cout << "\n";
	return in;
}

void Student::markCheck() {
	if (mark <= 2) {
		cout << "������ �������������������\n";
	}
	else {
		if (mark > 2) {
			cout << "������ �����������������\n";
		}
	}
}
void Student::show() {
	cout << "\n���:" << name;
	cout << "\n�������:" << age;
	cout << "\n�������:" << subject;
	cout << "\n������:" << mark;
	cout << "\n";
}