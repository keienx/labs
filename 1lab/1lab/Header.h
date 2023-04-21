#pragma once

class progression {
private:
    double first;
    unsigned int second;
public:
    void init(double, int);
    void read();
    void show();
    double element(int);
};