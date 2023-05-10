#include "Print.h"

Print::~Print(void) {}

Print::Print(void) {
	name = "";
	author = "";
}

Print::Print(string N, string A) {
	name = N;
	author = A;
}

Print::Print(const Print& P) {
	name = P.name;
	author = P.author;
}

void Print::Show() {
	cout << "\nИмя: " << name;
	cout << "\nАвтор: " << author << "\n";
}

void Print::Input() {
	getline(cin, name);
	cout << "Имя? "; 
	getline(cin, name);
	cout << "Автор? "; 
	getline(cin, author);
}

Print& Print::operator=(const Print& p) {
	if (&p == this) {
		return *this;
	}
	name = p.name;
	author = p.author;
	return *this;
}
