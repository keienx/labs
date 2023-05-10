#include "Pair.h"

Pair::Pair(){
	first = 0;
	second = 0;
}
Pair::Pair(int first, double second){
	this->first = first;
	this->second = second;
}
Pair::Pair(const Pair& obj){
	this->first = obj.first;
	this->second = obj.second;
}

Pair::~Pair(){}

Pair Pair::operator-(Pair& pair) const{
	Pair temp = *this;
	temp.first -= pair.first;
	temp.second -= pair.second;
	return temp;
}
Pair Pair::operator+(Pair& pair) const{
	Pair temp = *this;
	temp.first += pair.first;
	temp.second += pair.second;
	return temp;
}
Pair Pair::operator+(int data) const{
	Pair temp = *this;
	temp.first += data;
	return temp;
}
Pair Pair::operator+(double data) const{
	Pair temp = *this;
	temp.second += data;
	return temp;
}
Pair& Pair::operator++(){
	++first;
	++second;
	return *this;
}
Pair Pair::operator++(int){
	Pair temp = *this;
	++first;
	++second;
	return temp;
}
Pair Pair::operator*(Pair& pair){
	Pair temp;
	temp.first = this->first * pair.first;
	temp.second = this->second * pair.second;
	return temp;
}
Pair& Pair::operator=(const Pair& pair){
	if (this == &pair) {
		return *this;
	}
	first = pair.first;
	second = pair.second;
	return *this;
}

ostream& operator<<(ostream& out, const Pair& obj){
	out << "(" << obj.first << " : " << obj.second << ")";
	return out;
}
istream& operator>>(istream& in, Pair& obj){
	cout << "first (int): ";
	in >> obj.first;
	cout << "second (double): ";
	in >> obj.second;
	return in;
}
