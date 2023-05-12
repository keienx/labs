#include "Stack.h"

#include <iostream>

using namespace std;

int main(){
	system("color F0");
	srand(time(NULL));
	Stack a(7);
	cout << a;
	int num;
	cout << "¬ведите добавл€емый элемент: ";
	cin >> num;
	a.popback();
	a.pushback(num);
	cout << a;
	return 0;
}