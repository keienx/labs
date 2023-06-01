#include "Stack.h"

#include <iostream>
#include <Windows.h>

using namespace std;

int main(){
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	system("color F0");
	srand(time(NULL));
	Stack a(7);
	cout << a;
	int num;
	cout << "Введите добавляемый элемент: ";
	cin >> num;
	a.popback();
	a.pushback(num);
	cout << a;
	return 0;
}
