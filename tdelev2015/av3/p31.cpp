#include <iostream>
using namespace std;

class Square {
private:
	float a;
public:

	Square(float a = 0) {
		cout << "constructor: " << a << endl;
		this->a = a;
	}
	~Square() {
		cout << "destructor:" << a << endl;
	}

	float area() {
		return a * a;
	}
	float perimeter() {
		return 4 * a;
	}

	void setA(float a) {
		this->a = a;
	}

};

int main() {
	Square s;
	s.a = 5;
	float f;
	cin >> f;
	s.setA(3.2);
	Square s2(f);
	cout << "P (s): " << s.area() << endl;
	cout << "P (s2): " << s2.area() << endl;
	cout << "L (s2): " << s2.perimeter() << endl;
	return 0;
}