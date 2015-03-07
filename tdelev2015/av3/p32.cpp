#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
	float a, b, c;
public:
	Triangle(float a, float b, float c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	float area() {
		float s = perimeter() / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}

	float perimeter() {
		return a + b + c;
	}
};

int main() {
	float a, b, c;
	cin >> a >> b >> c;

	Triangle t(a, b, c);
	cout << "P: " << t.area() << endl;
	cout << "L: " << t.perimeter() << endl;
	return 0;
}