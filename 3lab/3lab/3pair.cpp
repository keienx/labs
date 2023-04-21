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
    cout << "��������� " << *this << " � " << d << '\n';
    this->first = this->first - d.first;
    this->second = this->second - d.second;
    cout << "���������� ";
    return *this;
}

Pair Pair::operator+(const int& d) {
    cout << "�������� " << *this << " � " << d << '\n';
    this->first = this->first + d;
    cout << "���������� ";
    return *this;
}

Pair Pair::operator+(const double& d) {
    cout << "�������� " << *this << " � " << d << '\n';
    this->second = this->second - d;
    cout << "���������� ";
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