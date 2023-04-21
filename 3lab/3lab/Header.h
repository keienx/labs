#pragma once
#include <iostream>

using namespace std;

class Pair{
private:
    int first;
    double second;
public:
    Pair() {
        first = 0;
        second = 0;
    }

    Pair(int f, double s) {
        first = f;
        second = s;
    }

    Pair(const Pair& d) {
        first = d.first;
        second = d.second;
    }

    ~Pair() {};

    Pair&operator=(const Pair& );
    Pair operator+(const int&);
    Pair operator+(const double& );
    Pair operator-(const Pair&);

    friend istream& operator>>(istream& in, Pair& d); 
    friend ostream& operator<<(ostream& out, const Pair& d);
};