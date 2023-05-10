#include "Vector.h"
#include "Dialog.h"
#include "Event.h"
#include "Magazin.h"
#include "Object.h"
#include "Print.h"
#include <Windows.h>

int main() {
	system("color F0");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	cout << "m: Создать группу\n";
	cout << "+: Добавить элемент\n";
	cout << "-: Удалить группу\n";
	cout << "s: Вывести содержимое группы на экран\n";
	cout << "z: Имена групп\n";
	cout << "q: Конец работы\n";
	Dialog D;
	D.Execute();
	return 0;
}
