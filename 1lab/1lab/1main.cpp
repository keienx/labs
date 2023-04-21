#include <iostream>
#include "Header.h"
#include <windows.h>

using namespace std;

int main() {
    system("chcp 1251 >> null");
    progression one;
    one.init(2, 3);
    /*one.read();*/
    one.show();
    cout << one.element(3);
}