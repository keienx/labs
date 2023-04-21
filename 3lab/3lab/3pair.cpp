#include "Header.h"
#include <iostream>

using namespace std;

Pair& Pair::operator=(const Pair& d) {
    if (&d == this) {
        return *this;
    }
    first = d.first;
    second = d.second;
}
Pair Pair::operator-(const Pair& d) {
    cout << "Вычитание " << *this << " и " << d << '\n';
    this->first = this->first - d.first;
    this->second = this->second - d.second;
    cout << "Получилось ";
    return *this;
}

Pair Pair::operator+(const int& d) {
    cout << "Сложение " << *this << " и " << d << '\n';
    this->first = this->first + d;
    cout << "Получилось ";
    return *this;
}

Pair Pair::operator+(const double& d) {
    cout << "Сложение " << *this << " и " << d << '\n';
    this->second = this->second - d;
    cout << "Получилось ";
    return *this;
}

istream& operator>>(istream& in, Pair& d) {
    cout << "First: ";
    in >> d.first;
    cout << "Second: ";
    in >> d.second;
    return in;
}

ostream& operator<<(ostream& os, const Pair& d) {
    return os << "(" << d.first << " : " << d.second << ")";
}