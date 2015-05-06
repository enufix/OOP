#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
// base class
class GeometricShape {
protected:
	float height;
public:
	GeometricShape(const float height = 0) : height(height) {
	}

	virtual void print() const {
		cout << "H: " << height << endl;
	}

	virtual float volume() const  { };

	virtual char* getInfo() const { };

	bool operator>(const GeometricShape &gs) const {
		return volume() > gs.volume();
	}

	friend ostream& operator<<(ostream &out, const GeometricShape &gs) {
		out << "H: " << gs.height << endl;
		out << gs.getInfo() << endl;
		return out;
	}
};



class Cylinder : public GeometricShape {
private:d
	float radius;
public:
	Cylinder(const float height = 0, const float radius = 0) : GeometricShape(height) {
		this->radius = radius;
	}

	void print() const {
		cout << "Cylinder" << endl;
		//cout << "H: " << height << endl;
		GeometricShape::print();
		cout << "R: " << radius << endl;
	}

	float volume() const {
		return radius * radius * 3.14 * height;
	}

	char* getInfo() const {
		return "Cylinder";
	}
};

class Cone : public GeometricShape {
private:
	float radius;
public:
	Cone(const float height = 0, const float radius = 0) : GeometricShape(height) {
		this->radius = radius;
	}

	void print() const {
		cout << "Cone" << endl;
		//cout << "H: " << height << endl;
		GeometricShape::print();
		cout << "R: " << radius << endl;
	}

	float volume() const {
		return radius * radius * 3.14 * height / 3;
	}
	char* getInfo() const {
		return "Cone";
	}
};

class Cuboid : public GeometricShape {
private:
	float a, b;
public:
	Cuboid(const float height = 0, const float a = 0, const float b = 0) : GeometricShape(height) {
		this->a = a;
		this->b = b;
	}

	void print() const {
		cout << "Cuboid" << endl;
		//cout << "H: " << height << endl;
		GeometricShape::print();
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
	}

	float volume() const {
		return a * b * height;
	}

	char* getInfo() const {
		return "Cuboid";
	}
};

void compare(const GeometricShape &g1, const GeometricShape &g2) {
	if(g1 > g2) {
		cout << g1;
		//g1.print();
	} else {
		cout << g2;
		//g2.print();
	}
}

float totalVolume(GeometricShape **gs, int n) {
	float total = 0;
	for(int i = 0; i < n; ++i) {
		total += gs[i]->volume();
	}
	return total;
}

int main() {

	Cuboid cc(15, 5, 8);
	Cone c(13, 8);
	Cylinder cl(12, 9);
	GeometricShape *g[3];
	g[0] = &cc;
	g[1] = &c;
	g[2] = &cl;
	float vol = totalVolume(g, 3);
	cout << "Total volume: " << vol << endl;
	compare(c, cl);
	compare(cl, cc);
	return 0;
}