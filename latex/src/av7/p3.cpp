#include <iostream>
#include <cstring>
using namespace std;

class GeometricShape {
protected:
	float height;
public:
	GeometricShape(const float height = 0) : this->height(height) {
	}

	virtual void print() = 0;

	virtual float volume() = 0;

	float getHeight() {
		return heigth;
	}
};

class Cylinder : public GeometricShape {
private:
	float radius;
public:
	Cylinder(const float height = 0, const float radius = 0) : GeometricShape(height) {
		this->radius = radius;
	}

	void print() {
		cout << "Cylinder" << endl;
		cout << "H: " << height << endl;
		cout << "R: " << radius << endl;
	}

	void volume() {
		
	}
}