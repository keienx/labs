#include <iostream>
#include "Header.h"

using namespace std;

void progression::init(double First, int Second) {
    first = First;
    second = Second;
}

void progression::read() {
    bool f = false;
    cout << "Введите значение переменной first\n";
    while (f == false) {
        cin >> first;
        if (!(cin.good())) {
            cin.clear();
            cin.ignore();
        }
        if (int(first) + 1 != first + 1) {
            f = true;
        }
    }
    cout << "Введите значение переменной second\n";
    while (!(cin >> second)) {
        cin.clear();
        cin.ignore();
    }
}

void progression::show() {
    cout << "first => " << first << '\n';
    cout << "second => " << second << '\n';
}

double progression::element(int j) {
    double aj;
    aj = first * pow(second, j-1);
    return aj;
}
