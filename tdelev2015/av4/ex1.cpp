#include <iostream>
#include <cstring>
using namespace std;

class A {
private:
	char *x;
public:
	A(char *x) {
		this->x = new char[strlen(x) + 1];
		strcpy(this->x, x);
	}
	A(const A &a) {
		x = new char[strlen(a.x) + 1];
		strcpy(x, a.x);
	}
	void print() {
		cout << "X: " << x << endl;
	}
	void setX(char *x) {
		strcpy(this->x, x);
	}
	~A() {
		delete [] x;
	}
};

int main() {
	A a("Hello World fdsfdsfdsfsd fdsf");
	A b = a;
	a.print();
	b.print();
	b.setX("FINKI");
	a.print();
	b.print();
	return 0;

}