#include "Pair.h"
#include "file_work.h" 
#include <iostream> 
#include <fstream>
#include <string> 
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	system("color F0");
	Pair p, temp; 
	int k, c, num, count; 
	double plus; 
	char file_name[30];
	do {
		system("pause"); system("cls");
		cout << "1. Создать список";
		cout << "\n2. Вывести файл";
		cout << "\n3. Удалить пары, меньшие заданной пары";
		cout << "\n4. Добавить несколько пар после пары с заданным номером";
		cout << "\n0. Bыxoд\n";
		cin >> c;
		switch (c) {
		case 1:
			cout << "Имя фaйлa: ";
			cin >> file_name;
			k = make_file(file_name);
			if (k < 0) {
				cout << "Невозможно создать файл \n";
			}
		case 2:
			cout << "Имя файла: ";
			cin >> file_name;
			k = print_file(file_name);
			if (k == 0) {
				cout << "Пустой файл\n";
			}
			break;
		case 3:
			cout << "Имя файла: ";
			cin >> file_name;
			cin >> temp;
			k = del_file(file_name, temp);
			if (k < 0) {
				cout << "Невозможно считать файл\n";
			}
			break;
		case 4:
			cout << "Имя файлa: "; cin >> file_name;
			cout << "После какого номера: "; cin >> num;
			cout << "Cколько: "; cin >> count;
			k = add_file(file_name, num, count);
			if (k < 0) {
				cout << "Невозможно считать файл\n";
			}
			if (k == 0) {
				k = add_end(file_name, count);
			}
			break;
		case 5:
			cout << "Имя файлa: "; 
			cin >> file_name;
			cout << "Введите число, которое хотите добавить: ";
			cin >> plus;
			k = change_file(file_name, plus);
			if (k < 0) {
				cout << "невозможно считать файл\n";
			}
			break;
		}
	} while (c != 0);
	return 0;
}
