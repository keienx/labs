#include "Magazin.h"

Magazin::~Magazin(void) {}

Magazin::Magazin(void) {
	pages = 0;
}

Magazin::Magazin(string N, string A, int P) : Print(N, A) {
	pages = P;
}

Magazin::Magazin(const Magazin& P) {
	name = P.name;
	author = P.author;
	pages = P.pages;
}


void Magazin::Show() {
	cout << "\n���: " << name;
	cout << "\n�����: " << author;
	cout << "\n��������: " << pages << "\n";
}

void Magazin::Input() {
	getline(cin, name);
	cout << "���? "; 
	getline(cin, name);
	cout << "�����? "; 
	getline(cin, author);
	cout << "���������� �������? "; 
	cin >> pages;
}

Magazin& Magazin::operator=(const Magazin& p) {
	if (&p == this) return *this;
	name = p.name;
	author = p.author;
	pages = p.pages;
	return *this;
}