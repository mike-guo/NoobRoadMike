#include <iostream>
using namespace std;

class A {
private:
	int _a;
public:
	A() : _a(1) { cout << "A()" << endl; }
	~A() { cout << "~A()" << endl; }
	void print() { cout << _a << endl; }
};

class B : public A {
private:
	int _a;
public:
	B() : _a(2) {}
};

#define Double(a, b) a + b

void ClassTest_test() {
	A * p = new A[10];
	delete[] p;

	int * p_int = new int[10];
	for (int i = 0; i < 10; i++) {
		p_int[i] = i+1;
	}
	cout << p_int[1] << endl;
	delete[] p_int;
	cout << p_int[1] << endl;


	B b;
	b.print();


	char c[5], *pc = c;
	pc = "abcd";


	cout << Double(3, 4) * Double(3, 4) << endl;

	system("pause");
}