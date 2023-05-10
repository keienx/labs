#include "List.h"
#include "Error.h"
#include <iostream>
#include <exception>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("color F0");
    try{
        // 1.
        List A(5);
        //cout << "A: " << A;
        //cout << A[5] << "\n";
        List B(5);
        // 2.
        //List B(4);
        //cout << "A: " << A;
        //cout << "B: " << B;
        //List C = A * B;
        //cout << "C: " << C << "\n";

        // 3. B + const, const > b.size
        //cout << "A: " << A;
        //cout << "B: " << B;
        //cout << B + 7;
    }
    catch (Error& e) {
        e.what();
    }
    catch (...) {
        cout << "Произошло неизвестное исключение"<< "\n";
    }
    return 0;
}
