#include <iostream>
#include "Header.h"

using namespace std;

int main() {
    system("chcp 1251 >> null");
    Pair a;
    Pair b(2, 7.3);
    Pair c(6, 5.25);
    cin >> a;
    cout << a - b << '\n' << '\n';
    cout << b + 4 << '\n';
    cout << c + 5.3 << '\n';
}