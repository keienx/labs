#include "person.h"

Person& Person::operator =(const Person& t) {
	name = t.name;
	age = t.age;
	return *this;
}

ostream& operator<<(ostream& out, const Person& t) {
	return (out << "���: " << t.name << "\n�������: " << t.age << "\n\n");
}

istream& operator>>(istream& in, Person& t) {
	cout << "���?: ";
	in >> t.name;
	cout << "�������?: ";
	in >> t.age;
	cout << "\n";
	return in;
}