#pragma once 
#include <string> 
#include <iostream> 
using namespace std;
class Error {
public:
	virtual void what() {};
};
class IndexError :
	public Error {
protected:
	string msg;
public:
	IndexError(){
		msg = "Ошибка в индексе\n";
	}
	virtual void what(){
		cout << msg;
	}
};
class SizeError :
	public Error {
protected:
	string msg;
public:
	SizeError(){
		msg = "Ошибка в размере\n";
	}
	virtual void what(){
		cout << msg;
	}
};
class NumberError :
	public Error {
protected:
	string msg;
public:
	NumberError(){
		msg = "Ошибка в номере\n";
	}
	virtual void what(){
		cout << msg;
	}
};
