#include "list.h"
#include "pair.h"

int main(){
	system("chcp 1251 >> null");

	List<Pair> A, B;
	Pair p1(10, 11.1), p2(15, 16.5);

	A.push_back(p1);
	p1 = p1 + 4;
	p1 = p1 + 4.4;
	A.push_back(p1);
	cout << "List<Pair>(A): ";
	A.show_list();
	cout << "A[0]: " << A[0] << "\n";
	cout << "Размер A(): " << A() << "\n" << "\n";

	B.push_back(p2);
	p2 = p2 + 6;
	p2 = p2 + 6.6;
	B.push_back(p2);
	B.push_back(p1);
	cout << "List<Pair>(B): "; 
	B.show_list();
	cout << "B[1]: " << B[1] << "\n";
	cout << "Размер B(): " << B() << "\n" << "\n";

	A = A * B;
	cout << "(A = A * B) == ";
	A.show_list();

	return 0;
}

