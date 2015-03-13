#include <iostream>
using namespace std;

class Square {
private:
	float side;
public:
	Square(float side = 0) {
		//cout << "s: " << (*this).side << endl;
		this->side = side;
		cout << "constructor: " << side << endl; 
	}

	~Square() {
		cout << "destructor: " << side << endl;
	}

	void printArea() {
		cout << "area: " << side * side << endl;
	}

	float area() {
		return side * side;
	}

};

int main() {
	Square s;
	Square s1(5);
	cout << "a: " << s1.area(3) << endl;
	return 0;
}