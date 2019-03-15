#include <iostream>

using namespace std;
//����

class D
{
public:
	D() { cout << "D()" << endl; }
	~D() { cout << "~D()" << endl; }
protected:
	int d;
};

class B :public D
{
public:
	B() { cout << "B()" << endl; }
	~B() { cout << "~B()" << endl; }
protected:
	int b;
};

class A :public D
{
public:
	A() { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
protected:
	int a;
};

class C :public B, public A
{
public:
	C() { cout << "C()" << endl; }
	~C() { cout << "~C()" << endl; }
protected:
	int c;
};

int main()
{
	cout << "Hello World!" << endl;
	C c;   //D, B, A ,C
	cout << sizeof(c) << endl;
	return 0;
}