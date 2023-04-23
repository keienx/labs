#include "Header.h"
#include <iostream>
#include <string>

using namespace std;

//функция для возврата объекта как результата
//функция для передачи объекта как параметра

void print_salary(salary t){
	t.show();
}
int main(){
	system("chcp 1251 >> null");
	//конструктор без параметров
	salary t1;
	t1.show();
	//коструктор с параметрами
	salary t2("Тимофей", 100000, 10);
	t2.show();
	salary t3 = t2;
	print_salary(t3);
	//конструктор копирования
}
