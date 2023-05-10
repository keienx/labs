#include "person.h"

Person& Person::operator =(const Person& t) {
	name = t.name;
	age = t.age;
	return *this;
}

ostream& operator<<(ostream& out, const Person& t) {
	return (out << "Имя: " << t.name << "\nВозраст: " << t.age << "\n\n");
}

istream& operator>>(istream& in, Person& t) {
	cout << "Имя?: ";
	in >> t.name;
	cout << "Возраст?: ";
	in >> t.age;
	cout << "\n";
	return in;
}
