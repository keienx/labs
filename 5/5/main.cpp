#include "object.h"
#include "person.h"
#include "student.h"
#include "vector.h"

int main(){
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	Vector v(10);
	Person a;
	cin >> a;
	Student b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
	b.markCheck();

	return 0;
}