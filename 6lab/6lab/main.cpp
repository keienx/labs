#include "List.h"

int main(){
	system("color F0");
	system("chcp 1251 >> null");
	List A, B, C;
	A.push_back(10);
	A.push_back(84);
	A.push_back(3);
	A.push_back(-73);

	B.push_back(11);
	B.push_back(11);

	C = A * B;

	cout << "Список C: ";
	C.show_list();
	cout << "Размер: " << C() << "\n" << "\n";

	cout << "Элемент C[0]: " << C[0] << "\n";
	cout << "Изменить значение C[0] на 150" << "\n"; 
	C[0] = 150;

	cout << "Список C: "; 
	C.show_list();

	cout << "\nСписок A: ";

	for (auto it = A.first(); it != A.last(); ++it)
		cout << (*it) << " ";
	cout << "\n";

	return 0;
}